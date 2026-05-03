const GITHUB_OWNER = 'Shuvam-Banerji-Seal';
const GITHUB_REPO = 'C-Programming-for-Beginners';
const GITHUB_API = `https://api.github.com/repos/${GITHUB_OWNER}/${GITHUB_REPO}`;
const RAW_BASE = `https://raw.githubusercontent.com/${GITHUB_OWNER}/${GITHUB_REPO}/main`;

const MODULES = [
  { id: '01-basics', num: 1, name: 'Getting Started with C', level: 'beginner', dir: '01-basics',
    desc: 'Introduction to C programming, setting up your environment, compilation process, and writing your first programs like Hello World.', color: '#aed581' },
  { id: '02-variables-and-types', num: 2, name: 'Variables & Data Types', level: 'beginner', dir: '02-variables-and-types',
    desc: 'Variables, primitive data types, type conversion, operators, and pre/post increment/decrement operations.', color: '#7ec8e3' },
  { id: '03-control-flow', num: 3, name: 'Control Flow', level: 'beginner', dir: '03-control-flow',
    desc: 'Conditional statements, switch case, loops (for, while, do-while), break/continue, and nested loops.', color: '#d4a373' },
  { id: '04-functions', num: 4, name: 'Functions', level: 'beginner', dir: '04-functions',
    desc: 'Function declaration & definition, parameters, scope, recursion, and function pointers.', color: '#c3aed6' },
  { id: '05-arrays-and-strings', num: 5, name: 'Arrays & Strings', level: 'beginner', dir: '05-arrays-and-strings',
    desc: 'One-dimensional and multi-dimensional arrays, character arrays, string manipulation without string.h.', color: '#e8a0bf' },
  { id: '06-pointers', num: 6, name: 'Pointers', level: 'intermediate', dir: '06-pointers',
    desc: 'Pointer basics, pointer arithmetic, pointers with arrays & functions, and pointer-to-pointer concepts.', color: '#aed581' },
  { id: '07-memory-management', num: 7, name: 'Memory Management', level: 'intermediate', dir: '07-memory-management',
    desc: 'Stack vs heap, dynamic memory allocation (malloc, calloc, realloc, free), memory leaks, and debugging.', color: '#7ec8e3' },
  { id: '08-structures-unions', num: 8, name: 'Structures & Unions', level: 'intermediate', dir: '08-structures-unions',
    desc: 'Structures, nested structures, arrays of structures, unions, bit fields, typedef, and enum.', color: '#d4a373' },
  { id: '09-file-io', num: 9, name: 'File I/O', level: 'intermediate', dir: '09-file-io',
    desc: 'File handling, reading/writing text and binary files, file positioning, and error handling.', color: '#c3aed6' },
  { id: '10-preprocessor', num: 10, name: 'Preprocessor & Macros', level: 'intermediate', dir: '10-preprocessor',
    desc: 'Preprocessor directives, macros, conditional compilation, header guards, and common preprocessor tricks.', color: '#e8a0bf' },
  { id: '11-data-structures', num: 11, name: 'Data Structures', level: 'advanced', dir: '11-data-structures',
    desc: 'Linked lists (singly & doubly), stacks, queues, hash tables, and complexity analysis with diagrams.', color: '#aed581' },
  { id: '12-advanced-data-structures', num: 12, name: 'Advanced Data Structures', level: 'advanced', dir: '12-advanced-data-structures',
    desc: 'BST, AVL trees, red-black trees, heaps, priority queues, graphs, and complete DSA with visual diagrams.', color: '#7ec8e3' },
  { id: '13-debugging-gdb', num: 13, name: 'Debugging with GDB', level: 'advanced', dir: '13-debugging-gdb',
    desc: 'GDB basics, breakpoints, stepping through code, examining variables, and advanced debugging techniques.', color: '#d4a373' },
  { id: '14-gtk4-gui', num: 14, name: 'GTK4 GUI Programming', level: 'advanced', dir: '14-gtk4-gui',
    desc: 'Introduction to GTK4, setting up GUI development, creating windows & widgets, and event handling.', color: '#c3aed6' },
  { id: '15-game-projects', num: 15, name: 'Game Development', level: 'advanced', dir: '15-game-projects',
    desc: 'Console-based games like Tic-Tac-Toe, Snake, and Sudoku with game loops and state management.', color: '#e8a0bf' },
  { id: '16-network-programming', num: 16, name: 'Network Programming', level: 'expert', dir: '16-network-programming',
    desc: 'Socket programming, TCP/IP communication, UDP, HTTP client/server, and multi-threaded servers.', color: '#aed581' },
  { id: '17-machine-learning', num: 17, name: 'Machine Learning in C', level: 'expert', dir: '17-machine-learning',
    desc: 'ML concepts, perceptron implementation, neural networks from scratch, and training algorithms.', color: '#7ec8e3' },
  { id: '18-digit-recognition', num: 18, name: 'Digit Recognition', level: 'expert', dir: '18-digit-recognition',
    desc: 'MNIST dataset, image processing in C, building a digit recognizer, and optimization techniques.', color: '#d4a373' },
  { id: '19-scientific-computing', num: 19, name: 'Scientific Computing', level: 'expert', dir: '19-scientific-computing',
    desc: 'Numerical methods, matrix operations, molecular dynamics simulations, and physics simulations.', color: '#c3aed6' },
  { id: '20-professional-dev', num: 20, name: 'Professional Development', level: 'expert', dir: '20-professional-dev',
    desc: 'Build systems (Make, CMake), unit testing, code style, profiling, optimization, and version control.', color: '#e8a0bf' }
];

const LEVELS = [
  { id: 'beginner', name: 'Beginner', range: 'Modules 1-5', desc: 'Start here if you are new to programming. Learn the fundamentals of C syntax, control flow, and basic data structures.' },
  { id: 'intermediate', name: 'Intermediate', range: 'Modules 6-10', desc: 'Master pointers, memory management, structures, file I/O, and the preprocessor.' },
  { id: 'advanced', name: 'Advanced', range: 'Modules 11-15', desc: 'Dive into complex data structures, debugging, GUI programming, and game development.' },
  { id: 'expert', name: 'Expert', range: 'Modules 16-20', desc: 'Explore networking, machine learning, scientific computing, and professional development practices.' }
];

async function fetchFromGitHub(path) {
  const resp = await fetch(`${RAW_BASE}/${path}`);
  if (!resp.ok) throw new Error(`HTTP ${resp.status}: ${path}`);
  return resp.text();
}

function mdRender(md) {
  const escape = (t) => t.replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;').replace(/"/g,'&quot;');
  const inline = (t) => t
    .replace(/`([^`]+)`/g, '<code>$1</code>')
    .replace(/\*\*([^*]+)\*\*/g, '<strong>$1</strong>')
    .replace(/\*([^*]+)\*/g, '<em>$1</em>')
    .replace(/\[([^\]]+)\]\(([^)]+)\)/g, '<a href="$2" target="_blank" rel="noopener">$1</a>');

  const lines = md.split('\n');
  let html = '', inList = false, listType = '', inCode = false;
  for (let i = 0; i < lines.length; i++) {
    let l = lines[i];
    if (l.startsWith('```')) {
      if (inCode) { html += '</code></pre>\n'; inCode = false; }
      else { html += '<pre><code>'; inCode = true; }
      continue;
    }
    if (inCode) { html += escape(l) + '\n'; continue; }

    if (l.startsWith('# ')) html += `<h1>${inline(l.slice(2).trim())}</h1>\n`;
    else if (l.startsWith('## ')) html += `<h2>${inline(l.slice(3).trim())}</h2>\n`;
    else if (l.startsWith('### ')) html += `<h3>${inline(l.slice(4).trim())}</h3>\n`;
    else if (l.startsWith('#### ')) html += `<h4>${inline(l.slice(5).trim())}</h4>\n`;
    else if (l.match(/^[-*]\s+/)) {
      const li = l.replace(/^[-*]\s+/, '');
      if (!inList || listType !== 'ul') {
        if (inList) html += `</${listType}>\n`;
        html += '<ul>\n'; inList = true; listType = 'ul';
      }
      html += `  <li>${inline(li)}</li>\n`;
    }
    else if (l.match(/^\d+[.)]\s/)) {
      const li = l.replace(/^\d+[.)]\s+/, '');
      if (!inList || listType !== 'ol') {
        if (inList) html += `</${listType}>\n`;
        html += '<ol>\n'; inList = true; listType = 'ol';
      }
      html += `  <li>${inline(li)}</li>\n`;
    }
    else {
      if (inList) { html += `</${listType}>\n`; inList = false; }
      if (l.startsWith('> ')) html += `<blockquote>${inline(l.slice(2).trim())}</blockquote>\n`;
      else if (l.startsWith('---')) html += '<hr>\n';
      else if (l.trim() === '') html += '\n';
      else html += `<p>${inline(l)}</p>\n`;
    }
  }
  if (inList) html += `</${listType}>\n`;
  if (inCode) html += '</code></pre>\n';
  return html;
}

async function loadHomeModules() {
  const grid = document.getElementById('module-grid');
  if (!grid) return;
  grid.innerHTML = LEVELS.map(level => {
    const mods = MODULES.filter(m => m.level === level.id);
    return `
      <div class="level-card" onclick="Router.navigate('modules',{module:'${mods[0]?.id}'})" style="animation-delay:${LEVELS.indexOf(level)*0.1}s">
        <div class="level-card-header">
          <span class="level-name">${level.name}</span>
          <span class="level-range">${level.range}</span>
        </div>
        <p class="level-desc">${level.desc}</p>
        <div class="level-modules">${mods.map(m => `<span class="module-chip">${m.num}. ${m.name}</span>`).join('')}</div>
      </div>`;
  }).join('');
}

async function loadModulesPage() {
  const list = document.getElementById('module-list');
  if (!list) return;
  list.innerHTML = '';
  const level = document.querySelector('.filter-btn.active')?.dataset.level || 'all';
  const filtered = level === 'all' ? MODULES : MODULES.filter(m => m.level === level);
  filtered.sort((a, b) => a.num - b.num).forEach((mod, i) => {
    const card = document.createElement('div');
    card.className = 'module-card';
    card.style.animationDelay = `${i * 0.05}s`;
    card.innerHTML = `
      <div class="module-card-header">
        <span class="module-num" style="color:${mod.color}">Module ${String(mod.num).padStart(2, '0')}</span>
        <span style="font-size:0.8rem;color:var(--text-muted);font-family:var(--font-mono)">${mod.level}</span>
      </div>
      <div class="module-name">${mod.name}</div>
      <div class="module-desc">${mod.desc}</div>`;
    card.addEventListener('click', () => Router.navigate('modules', { module: mod.id }));
    list.appendChild(card);
  });
}

async function loadModuleDetail(moduleId) {
  const container = document.getElementById('module-content');
  if (!container) return;
  container.innerHTML = '<div class="loading-container"><div class="loader"></div><p>Loading module content from GitHub...</p></div>';

  const mod = MODULES.find(m => m.id === moduleId);
  if (!mod) {
    container.innerHTML = '<div class="error-container"><h3>Module not found</h3></div>';
    return;
  }

  try {
    const [readme, files] = await Promise.all([
      fetchFromGitHub(`${mod.dir}/README.md`),
      fetch(`${GITHUB_API}/contents/${mod.dir}`).then(r => r.ok ? r.json() : [])
    ]);

    let html = mdRender(readme);

    const cFiles = Array.isArray(files) ? files.filter(f => f.name.endsWith('.c') || f.name.endsWith('.h')).sort((a, b) => a.name.localeCompare(b.name)) : [];

    if (cFiles.length > 0) {
      html += '<h2>Source Files</h2><p>Each file has an explanation and can be loaded into the editor:</p><div class="c-source-list">';

      for (const f of cFiles) {
        let desc = '';
        try {
          const mdPath = f.path.replace(/\.(c|h)$/, '.md');
          desc = await fetchFromGitHub(mdPath);
          desc = mdRender(desc);
        } catch { }

        let code = '';
        try {
          code = await fetchFromGitHub(f.path);
        } catch { }

        const codeEscaped = code.replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;').replace(/"/g,'&quot;');

        html += `
          <div class="c-source-item">
            <div class="c-source-header" onclick="this.nextElementSibling.nextElementSibling.classList.toggle('open')">
              <span class="c-source-name">${f.name}</span>
              <div class="c-source-actions">
                <button class="load-in-editor-btn" onclick="event.stopPropagation();document.dispatchEvent(new CustomEvent('load-file',{detail:{path:'${f.path}',name:'${f.name}'}}))">
                  <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><polygon points="5 3 19 12 5 21 5 3"/></svg>
                  Edit & Run
                </button>
              </div>
            </div>
            ${desc ? `<div class="c-source-desc">${desc}</div>` : ''}
            <div class="c-source-code">
              <div class="code-lang-label">
                <span>${f.name}</span>
                <span>C Source</span>
              </div>
              <pre>${codeEscaped}</pre>
            </div>
          </div>`;
      }
      html += '</div>';
    }

    container.innerHTML = `
      <div class="module-detail-header">
        <h1 style="color:${mod.color}">Module ${String(mod.num).padStart(2,'0')}: ${mod.name}</h1>
        <p style="color:var(--text-secondary);margin-bottom:24px">${mod.desc}</p>
      </div>
      <div class="module-body">${html}</div>`;
  } catch (err) {
    container.innerHTML = `<div class="error-container"><h3>Failed to load module</h3><p>${err.message}</p><p><a href="https://github.com/${GITHUB_OWNER}/${GITHUB_REPO}/tree/main/${mod.dir}" target="_blank">View on GitHub</a></p></div>`;
  }
}

async function loadRepoStats() {
  try {
    const resp = await fetch(GITHUB_API);
    if (resp.ok) {
      const data = await resp.json();
      const s = document.getElementById('repo-stars');
      const f = document.getElementById('repo-forks');
      if (s) s.textContent = data.stargazers_count ?? '-';
      if (f) f.textContent = data.forks_count ?? '-';
    }
  } catch { }
}

async function loadFileContent(path) {
  try { return await fetchFromGitHub(path); }
  catch { return null; }
}
