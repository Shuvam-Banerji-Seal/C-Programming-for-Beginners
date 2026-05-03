const EDITOR_KEY = 'c-course-editor-code';
const FILES_KEY = 'c-course-editor-files';

const DEFAULT_CODE = `#include <stdio.h>

int main() {
    printf("Hello, C Programming!\\n");
    return 0;
}`;

const EXAMPLE_CODES = {
  'Hello World': `#include <stdio.h>

int main() {
    printf("Hello, World!\\n");
    return 0;
}`,
  'Fibonacci': `#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    printf("First %d Fibonacci numbers:\\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\\n");
    return 0;
}`,
  'Factorial': `#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 12;
    printf("Factorial of %d = %llu\\n", n, factorial(n));
    return 0;
}`,
  'Pointers Demo': `#include <stdio.h>

int main() {
    int x = 42;
    int *ptr = &x;

    printf("Value of x: %d\\n", x);
    printf("Address of x: %p\\n", (void*)&x);
    printf("Pointer ptr: %p\\n", (void*)ptr);
    printf("Value via ptr: %d\\n", *ptr);

    *ptr = 100;
    printf("After *ptr = 100, x = %d\\n", x);
    return 0;
}`,
  'Array & Loop': `#include <stdio.h>

int main() {
    int arr[] = {5, 12, 8, 23, 16, 9, 3, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0, max = arr[0], min = arr[0];

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("\\nSum: %d\\n", sum);
    printf("Avg: %.2f\\n", (float)sum / n);
    printf("Max: %d, Min: %d\\n", max, min);
    return 0;
}`
};

const COMPILERS = {
  gcc: { id: 'g132', name: 'GCC 13.2' },
  clang: { id: 'clang1701', name: 'Clang 17.0.1' }
};

const API_URL = 'https://godbolt.org/api/compiler';

let editor = null;
let compileRunning = false;
let currentFilePath = null;
let fileTabs = {};

function flattenCE(arr) {
  if (!arr) return '';
  if (typeof arr === 'string') return arr;
  if (Array.isArray(arr)) return arr.map(x => x.text || x || '').join('');
  return String(arr);
}

async function compileCode(source, compilerId, options) {
  const body = {
    source,
    compiler: compilerId,
    options: {
      userArguments: options || '-std=c11 -Wall -Wextra',
      filters: {
        binary: false,
        commentOnly: true,
        demangle: true,
        directives: true,
        execute: true,
        intel: false,
        labels: true,
        libraryCode: false,
        trim: false,
        debug: false
      }
    },
    lang: 'c',
    allowStoreCodeDebug: false
  };

  const resp = await fetch(`${API_URL}/${compilerId}/compile`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json', 'Accept': 'application/json' },
    body: JSON.stringify(body)
  });
  if (!resp.ok) throw new Error(`Compiler API error: ${resp.status}`);
  return resp.json();
}

function initEditor() {
  const textarea = document.getElementById('code-editor');
  if (!textarea) return;

  const savedCode = localStorage.getItem(EDITOR_KEY) || DEFAULT_CODE;
  const savedFiles = JSON.parse(localStorage.getItem(FILES_KEY) || '{}');
  fileTabs = savedFiles;

  editor = CodeMirror.fromTextArea(textarea, {
    value: savedCode,
    mode: 'text/x-csrc',
    theme: 'dracula',
    lineNumbers: true,
    matchBrackets: true,
    autoCloseBrackets: true,
    styleActiveLine: true,
    indentUnit: 4,
    tabSize: 4,
    indentWithTabs: false,
    lineWrapping: false,
    gutters: ['CodeMirror-linenumbers', 'CodeMirror-foldgutter'],
    foldGutter: true,
    extraKeys: {
      'Ctrl-S': () => saveCode(),
      'Cmd-S': () => saveCode(),
      'Tab': 'indentMore',
      'Shift-Tab': 'indentLess',
      'Ctrl-/': 'toggleComment'
    }
  });

  editor.setValue(savedCode);
  saveCode();
  renderFileTabs();

  document.getElementById('compile-btn').addEventListener('click', doCompile);
  document.getElementById('clear-output').addEventListener('click', clearOutput);
  document.getElementById('reset-code').addEventListener('click', resetCode);
  document.getElementById('load-example').addEventListener('click', loadRandomExample);
  document.getElementById('compiler-select').addEventListener('change', saveConfig);
  document.getElementById('optimization-select').addEventListener('change', saveConfig);
  document.getElementById('copy-output').addEventListener('click', copyOutput);

  loadConfig();

  document.addEventListener('load-file', async (e) => {
    const { path, name } = e.detail;
    appendOutput(`Loading ${name} from GitHub...\n`, 'system');
    try {
      const content = await loadFileContent(path);
      if (content !== null) {
        addFileTab(name, path, content);
        switchToFile(name);
        appendOutput(`Loaded: ${name}\n`, 'system');
        showToast(`Loaded ${name}`, 'success');
      } else {
        appendOutput(`Failed to load ${name}\n`, 'error-line');
      }
    } catch (err) {
      appendOutput(`Error: ${err.message}\n`, 'error-line');
    }
  });

  let saveTimeout;
  editor.on('change', () => {
    clearTimeout(saveTimeout);
    saveTimeout = setTimeout(saveCode, 500);
    const name = getActiveTabName();
    if (name && fileTabs[name]) {
      fileTabs[name].code = editor.getValue();
      saveFileTabs();
    }
  });
}

function addFileTab(name, path, code) {
  if (fileTabs[name]) return;
  fileTabs[name] = { path, code, dirty: false };
  saveFileTabs();
  renderFileTabs();
}

function switchToFile(name) {
  if (!fileTabs[name]) return;
  currentFilePath = fileTabs[name].path;
  editor.setValue(fileTabs[name].code);
  saveCode();
  document.querySelectorAll('.file-tab').forEach(t => t.classList.toggle('active', t.dataset.name === name));
}

function getActiveTabName() {
  const active = document.querySelector('.file-tab.active');
  return active ? active.dataset.name : null;
}

function closeFileTab(name, e) {
  e.stopPropagation();
  delete fileTabs[name];
  saveFileTabs();
  renderFileTabs();
  const remaining = Object.keys(fileTabs);
  if (remaining.length > 0) {
    switchToFile(remaining[0]);
  }
}

function renderFileTabs() {
  const container = document.getElementById('file-tabs');
  if (!container) return;
  const names = Object.keys(fileTabs);
  if (names.length === 0) {
    container.innerHTML = '<span class="tab-placeholder">main.c</span>';
    return;
  }
  container.innerHTML = names.map(name => `
    <span class="file-tab${name === getActiveTabName() || (!getActiveTabName() && names.indexOf(name) === 0) ? ' active' : ''}" data-name="${name}" onclick="switchToFile('${name}')">
      ${name}
      <span class="tab-close" onclick="closeFileTab('${name}', event)">&times;</span>
    </span>
  `).join('');
  if (!getActiveTabName() && names.length > 0) switchToFile(names[0]);
}

function saveFileTabs() {
  localStorage.setItem(FILES_KEY, JSON.stringify(fileTabs));
}

function loadRandomExample() {
  const names = Object.keys(EXAMPLE_CODES);
  const name = names[Math.floor(Math.random() * names.length)];
  editor.setValue(EXAMPLE_CODES[name]);
  saveCode();
  clearOutput();
  appendOutput(`Loaded example: "${name}"\n`, 'system');
}

function saveCode() {
  if (!editor) return;
  localStorage.setItem(EDITOR_KEY, editor.getValue());
}

function saveConfig() {
  localStorage.setItem('c-course-compiler', document.getElementById('compiler-select').value);
  localStorage.setItem('c-course-optimization', document.getElementById('optimization-select').value);
}

function loadConfig() {
  const c = localStorage.getItem('c-course-compiler');
  const o = localStorage.getItem('c-course-optimization');
  if (c) document.getElementById('compiler-select').value = c;
  if (o) document.getElementById('optimization-select').value = o;
}

function clearOutput() {
  const output = document.getElementById('output-content');
  if (!output) return;
  output.innerHTML = '<div class="output-placeholder"><span class="prompt-symbol">$</span><span class="prompt-text">Write C code and hit Compile</span></div>';
  setStatus('idle', 'Ready');
}

function appendOutput(text, className = '') {
  const output = document.getElementById('output-content');
  if (!output) return;
  const ph = output.querySelector('.output-placeholder');
  if (ph) ph.remove();
  text.split('\n').forEach((line, i, arr) => {
    if (i === arr.length - 1 && line === '') return;
    const div = document.createElement('div');
    div.className = `output-line ${className}`;
    div.textContent = line;
    output.appendChild(div);
  });
  output.scrollTop = output.scrollHeight;
}

function setStatus(state, text) {
  const ind = document.querySelector('.status-indicator');
  const st = document.getElementById('output-status')?.querySelector('.status-text');
  if (ind) ind.className = `status-indicator ${state}`;
  if (st) st.textContent = text;
}

async function doCompile() {
  if (!editor || compileRunning) return;
  const source = editor.getValue().trim();
  if (!source) { appendOutput('Error: No code to compile.\n', 'error-line'); return; }

  const cc = document.getElementById('compiler-select').value;
  const oc = document.getElementById('optimization-select').value;
  const ci = COMPILERS[cc] || COMPILERS.gcc;

  compileRunning = true;
  const btn = document.getElementById('compile-btn');
  btn.disabled = true;
  btn.textContent = ' Compiling...';

  clearOutput();
  appendOutput(`[${ci.name} ${oc}] Compiling...\n`, 'system');
  setStatus('running', 'Compiling...');

  try {
    const args = `-std=c11 -Wall -Wextra ${oc}`;
    const result = await compileCode(source, ci.id, args);

    let hasErrors = false;

    appendOutput(`\n--- Build Output ---\n`, 'system');

    const buildOut = flattenCE(result.buildResult?.stdout);
    if (buildOut) appendOutput(buildOut, 'stdout');

    const buildErr = flattenCE(result.buildResult?.stderr);
    if (buildErr) {
      buildErr.split('\n').filter(l => l.trim()).forEach(line => {
        if (line.toLowerCase().includes('error')) {
          appendOutput(line + '\n', 'error-line');
          hasErrors = true;
        } else if (line.toLowerCase().includes('warning')) {
          appendOutput(line + '\n', 'warning-line');
        } else {
          appendOutput(line + '\n', 'stderr');
        }
      });
    }

    if (result.execResult) {
      appendOutput(`\n--- Program Output ---\n`, 'system');
      const execOut = flattenCE(result.execResult.stdout);
      if (execOut) appendOutput(execOut, 'stdout');

      const execErr = flattenCE(result.execResult.stderr);
      if (execErr) {
        appendOutput(`\n--- Runtime Diagnostic ---\n`, 'system');
        appendOutput(execErr + '\n', 'stderr');
        hasErrors = true;
      }

      if (result.execResult.code !== undefined) {
        const ec = result.execResult.code;
        appendOutput(`\n[Exit code: ${ec}]\n`, 'system');
        if (ec === 0 && !hasErrors) {
          setStatus('success', 'Compilation succeeded');
          showToast('Compilation successful!', 'success');
        } else {
          setStatus('error', `Exited with code ${ec}`);
        }
      }
    }

    if (!hasErrors && (!result.execResult || result.execResult.code === 0)) {
      if (!result.execResult) {
        setStatus('success', 'Compilation succeeded');
        showToast('Compilation successful!', 'success');
      }
    } else if (!hasErrors) {
      setStatus('success', 'Compilation succeeded');
    }

  } catch (err) {
    appendOutput(`\n--- Error ---\n`, 'system');
    appendOutput(`${err.message}\n`, 'error-line');
    appendOutput('\nThe online compiler may be unreachable. Your code compiles fine locally with GCC/Clang.\n', 'warning-line');
    setStatus('error', 'Compilation failed');
    showToast('Online compiler error: ' + err.message, 'error');
  }

  compileRunning = false;
  btn.disabled = false;
  btn.innerHTML = '<svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><polygon points="5 3 19 12 5 21 5 3"/></svg> Compile & Run';
}

function resetCode() {
  if (!editor) return;
  const name = getActiveTabName();
  if (name && fileTabs[name]) {
    delete fileTabs[name];
    saveFileTabs();
    renderFileTabs();
  }
  editor.setValue(DEFAULT_CODE);
  saveCode();
  clearOutput();
  appendOutput('Reset to default.\n', 'system');
  showToast('Code reset', 'info');
}

function copyOutput() {
  const output = document.getElementById('output-content');
  if (!output) return;
  const text = output.textContent;
  navigator.clipboard.writeText(text).then(() => {
    showToast('Output copied to clipboard', 'success');
  }).catch(() => {
    showToast('Failed to copy', 'error');
  });
}

function showToast(message, type = 'info') {
  const container = document.getElementById('toast-container');
  if (!container) return;
  const toast = document.createElement('div');
  toast.className = `toast ${type}`;
  toast.textContent = message;
  container.appendChild(toast);
  setTimeout(() => {
    toast.style.opacity = '0';
    toast.style.transform = 'translateX(100%)';
    toast.style.transition = 'all 0.3s ease';
    setTimeout(() => toast.remove(), 300);
  }, 3000);
}
