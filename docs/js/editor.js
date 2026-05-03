const EDITOR_KEY = 'c-course-editor-code';

const DEFAULT_CODE = `#include <stdio.h>

int main() {
    printf("Hello, C Programming!\\n");
    printf("Welcome to the interactive playground\\n");

    int a = 10, b = 20;
    int sum = a + b;
    printf("Sum of %d and %d is: %d\\n", a, b, sum);

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
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
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
    printf("Average: %.2f\\n", (float)sum / n);
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

async function compileCode(source, compilerId, options) {
  const body = {
    source,
    compiler: compilerId,
    options: {
      userArguments: options || '-std=c11 -Wall -Wextra',
      compilerOptions: { executorRequest: true },
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
    headers: {
      'Content-Type': 'application/json',
      'Accept': 'application/json'
    },
    body: JSON.stringify(body)
  });

  if (!resp.ok) throw new Error(`Compiler API error: ${resp.status}`);
  return resp.json();
}

function formatOutput(result) {
  let output = '';
  let hasError = false;

  if (result.code === 0 && result.execResult && result.execResult.stdout) {
    output += result.execResult.stdout;
  }

  if (result.buildResult && result.buildResult.stderr) {
    const lines = result.buildResult.stderr.split('\n').filter(l => l.trim());
    for (const line of lines) {
      if (line.toLowerCase().includes('error')) {
        output += `Error: ${line}\n`;
        hasError = true;
      } else if (line.toLowerCase().includes('warning')) {
        output += `Warning: ${line}\n`;
      } else {
        output += `${line}\n`;
      }
    }
  }

  if (result.execResult && result.execResult.stderr) {
    output += `\n--- Runtime Error ---\n${result.execResult.stderr}`;
    hasError = true;
  }

  if (result.execResult && result.execResult.buildResult && result.execResult.buildResult.stderr) {
    output += `\n${result.execResult.buildResult.stderr}`;
  }

  if (result.execResult && result.execResult.code && result.execResult.code !== 0) {
    output += `\n[Process exited with code ${result.execResult.code}]`;
  }

  if (!output.trim()) {
    output = 'Compilation successful. (No output)';
  }

  return { output, hasError };
}

function initEditor() {
  const textarea = document.getElementById('code-editor');
  if (!textarea) return;

  const savedCode = localStorage.getItem(EDITOR_KEY) || DEFAULT_CODE;

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
    extraKeys: {
      'Ctrl-S': () => saveCode(),
      'Cmd-S': () => saveCode(),
      'Tab': 'indentMore',
      'Shift-Tab': 'indentLess'
    }
  });

  editor.setValue(savedCode);
  saveCode();

  const compileBtn = document.getElementById('compile-btn');
  const clearBtn = document.getElementById('clear-output');
  const resetBtn = document.getElementById('reset-code');
  const loadExampleBtn = document.getElementById('load-example');
  const compilerSelect = document.getElementById('compiler-select');
  const optimizationSelect = document.getElementById('optimization-select');

  compileBtn.addEventListener('click', doCompile);
  clearBtn.addEventListener('click', clearOutput);
  resetBtn.addEventListener('click', resetCode);

  loadExampleBtn.addEventListener('click', () => {
    const names = Object.keys(EXAMPLE_CODES);
    const name = names[Math.floor(Math.random() * names.length)];
    editor.setValue(EXAMPLE_CODES[name]);
    saveCode();
    clearOutput();
    appendOutput(`Loaded example: "${name}"\n`, 'system');
  });

  compilerSelect.addEventListener('change', saveConfig);
  optimizationSelect.addEventListener('change', saveConfig);

  loadConfig();

  document.addEventListener('load-file', async (e) => {
    const { path, name } = e.detail;
    appendOutput(`Loading ${name} from GitHub...\n`, 'system');
    try {
      const content = await loadFileContent(path);
      if (content !== null) {
        editor.setValue(content);
        saveCode();
        appendOutput(`Loaded: ${name}\n`, 'system');
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
  });
}

function saveCode() {
  if (!editor) return;
  localStorage.setItem(EDITOR_KEY, editor.getValue());
}

function saveConfig() {
  const compiler = document.getElementById('compiler-select').value;
  const opt = document.getElementById('optimization-select').value;
  localStorage.setItem('c-course-compiler', compiler);
  localStorage.setItem('c-course-optimization', opt);
}

function loadConfig() {
  const compiler = localStorage.getItem('c-course-compiler');
  const opt = localStorage.getItem('c-course-optimization');
  if (compiler) document.getElementById('compiler-select').value = compiler;
  if (opt) document.getElementById('optimization-select').value = opt;
}

function clearOutput() {
  const output = document.getElementById('output-content');
  if (!output) return;
  output.innerHTML = `<div class="output-placeholder">
    <span class="prompt-symbol">$</span>
    <span class="prompt-text">Write some C code and hit Compile</span>
  </div>`;
  setStatus('idle', 'Ready');
}

function appendOutput(text, className = '') {
  const output = document.getElementById('output-content');
  if (!output) return;

  const placeholder = output.querySelector('.output-placeholder');
  if (placeholder) placeholder.remove();

  const lines = text.split('\n');
  lines.forEach((line, i) => {
    if (i === lines.length - 1 && line === '') return;
    const div = document.createElement('div');
    div.className = `output-line ${className}`;
    div.textContent = line;
    output.appendChild(div);
  });

  output.scrollTop = output.scrollHeight;
}

function setStatus(state, text) {
  const indicator = document.querySelector('.status-indicator');
  const statusText = document.getElementById('output-status')?.querySelector('.status-text');
  if (indicator) {
    indicator.className = `status-indicator ${state}`;
  }
  if (statusText) statusText.textContent = text;
}

async function doCompile() {
  if (!editor || compileRunning) return;

  const source = editor.getValue().trim();
  if (!source) {
    appendOutput('Error: No code to compile.\n', 'error-line');
    return;
  }

  const compilerChoice = document.getElementById('compiler-select').value;
  const optChoice = document.getElementById('optimization-select').value;
  const compilerInfo = COMPILERS[compilerChoice] || COMPILERS.gcc;
  const compilerId = compilerInfo.id;

  compileRunning = true;
  const compileBtn = document.getElementById('compile-btn');
  compileBtn.disabled = true;
  compileBtn.innerHTML = '<div class="loader" style="width:16px;height:16px;border-width:2px"></div> Compiling...';

  clearOutput();
  appendOutput(`Compiling with ${compilerInfo.name} ${optChoice}...\n`, 'system');
  setStatus('running', 'Compiling...');

  try {
    const args = `-std=c11 -Wall -Wextra ${optChoice}`;
    const result = await compileCode(source, compilerId, args);

    appendOutput(`\n--- Output ---\n`, 'system');

    if (result.execResult && result.execResult.stdout) {
      appendOutput(result.execResult.stdout, 'stdout');
    }

    if (result.buildResult && result.buildResult.stderr) {
      const lines = result.buildResult.stderr.split('\n').filter(l => l.trim());
      for (const line of lines) {
        if (line.toLowerCase().includes('error')) {
          appendOutput(line + '\n', 'error-line');
        } else if (line.toLowerCase().includes('warning')) {
          appendOutput(line + '\n', 'warning-line');
        }
      }
    }

    if (result.execResult && result.execResult.stderr) {
      appendOutput(`\n--- Runtime Diagnostic ---\n`, 'system');
      appendOutput(result.execResult.stderr + '\n', 'stderr');
    }

    if (result.execResult && result.execResult.code !== undefined) {
      const exitCode = result.execResult.code;
      appendOutput(`\n[Process exited with code ${exitCode}]\n`, 'system');
      if (exitCode === 0) {
        setStatus('success', 'Compilation succeeded');
        showToast('Compilation successful!', 'success');
      } else {
        setStatus('error', `Exited with code ${exitCode}`);
      }
    } else {
      setStatus('success', 'Compilation succeeded');
      showToast('Compilation successful!', 'success');
    }
  } catch (err) {
    appendOutput(`\n--- Compilation Error ---\n`, 'system');
    appendOutput(`${err.message}\n`, 'error-line');
    appendOutput('\nHint: Make sure your code has a main() function and valid C syntax.\n', 'warning-line');
    setStatus('error', 'Compilation failed');
    showToast('Compilation failed: ' + err.message, 'error');
  }

  compileRunning = false;
  compileBtn.disabled = false;
  compileBtn.innerHTML = '<svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><polygon points="5 3 19 12 5 21 5 3"/></svg> Compile & Run';
}

function resetCode() {
  if (editor) {
    editor.setValue(DEFAULT_CODE);
    saveCode();
    clearOutput();
    appendOutput('Code reset to default example.\n', 'system');
    showToast('Code reset', 'info');
  }
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
