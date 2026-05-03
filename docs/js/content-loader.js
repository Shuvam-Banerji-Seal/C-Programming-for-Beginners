const GITHUB_OWNER = 'Shuvam-Banerji-Seal';
const GITHUB_REPO = 'C-Programming-for-Beginners';
const GITHUB_API = `https://api.github.com/repos/${GITHUB_OWNER}/${GITHUB_REPO}`;
const RAW_BASE = `https://raw.githubusercontent.com/${GITHUB_OWNER}/${GITHUB_REPO}/main`;

const MODULES = [
  { id: '01-basics', num: 1, name: 'Getting Started with C', level: 'beginner', dir: '01-basics',
    desc: 'Introduction to C programming, setting up your environment, compilation process, and writing your first programs like Hello World.', color: '#00ff88' },
  { id: '02-variables-and-types', num: 2, name: 'Variables & Data Types', level: 'beginner', dir: '02-variables-and-types',
    desc: 'Variables, primitive data types, type conversion, operators, and pre/post increment/decrement operations.', color: '#42a5ff' },
  { id: '03-control-flow', num: 3, name: 'Control Flow', level: 'beginner', dir: '03-control-flow',
    desc: 'Conditional statements, switch case, loops (for, while, do-while), break/continue, and nested loops.', color: '#ff8c42' },
  { id: '04-functions', num: 4, name: 'Functions', level: 'beginner', dir: '04-functions',
    desc: 'Function declaration & definition, parameters, scope, recursion, and function pointers.', color: '#b388ff' },
  { id: '05-arrays-and-strings', num: 5, name: 'Arrays & Strings', level: 'beginner', dir: '05-arrays-and-strings',
    desc: 'One-dimensional and multi-dimensional arrays, character arrays, string manipulation without string.h.', color: '#ff6b9d' },
  { id: '06-pointers', num: 6, name: 'Pointers', level: 'intermediate', dir: '06-pointers',
    desc: 'Pointer basics, pointer arithmetic, pointers with arrays & functions, and pointer-to-pointer concepts.', color: '#00ff88' },
  { id: '07-memory-management', num: 7, name: 'Memory Management', level: 'intermediate', dir: '07-memory-management',
    desc: 'Stack vs heap, dynamic memory allocation (malloc, calloc, realloc, free), memory leaks, and debugging.', color: '#42a5ff' },
  { id: '08-structures-unions', num: 8, name: 'Structures & Unions', level: 'intermediate', dir: '08-structures-unions',
    desc: 'Structures, nested structures, arrays of structures, unions, bit fields, typedef, and enum.', color: '#ff8c42' },
  { id: '09-file-io', num: 9, name: 'File I/O', level: 'intermediate', dir: '09-file-io',
    desc: 'File handling, reading/writing text and binary files, file positioning, and error handling.', color: '#b388ff' },
  { id: '10-preprocessor', num: 10, name: 'Preprocessor & Macros', level: 'intermediate', dir: '10-preprocessor',
    desc: 'Preprocessor directives, macros, conditional compilation, header guards, and common preprocessor tricks.', color: '#ff6b9d' },
  { id: '11-data-structures', num: 11, name: 'Data Structures', level: 'advanced', dir: '11-data-structures',
    desc: 'Linked lists (singly & doubly), stacks, queues, hash tables, and complexity analysis with diagrams.', color: '#00ff88' },
  { id: '12-advanced-data-structures', num: 12, name: 'Advanced Data Structures', level: 'advanced', dir: '12-advanced-data-structures',
    desc: 'BST, AVL trees, red-black trees, heaps, priority queues, graphs, and complete DSA with visual diagrams.', color: '#42a5ff' },
  { id: '13-debugging-gdb', num: 13, name: 'Debugging with GDB', level: 'advanced', dir: '13-debugging-gdb',
    desc: 'GDB basics, breakpoints, stepping through code, examining variables, and advanced debugging techniques.', color: '#ff8c42' },
  { id: '14-gtk4-gui', num: 14, name: 'GTK4 GUI Programming', level: 'advanced', dir: '14-gtk4-gui',
    desc: 'Introduction to GTK4, setting up GUI development, creating windows & widgets, and event handling.', color: '#b388ff' },
  { id: '15-game-projects', num: 15, name: 'Game Development', level: 'advanced', dir: '15-game-projects',
    desc: 'Console-based games like Tic-Tac-Toe, Snake, and Sudoku with game loops and state management.', color: '#ff6b9d' },
  { id: '16-network-programming', num: 16, name: 'Network Programming', level: 'expert', dir: '16-network-programming',
    desc: 'Socket programming, TCP/IP communication, UDP, HTTP client/server, and multi-threaded servers.', color: '#00ff88' },
  { id: '17-machine-learning', num: 17, name: 'Machine Learning in C', level: 'expert', dir: '17-machine-learning',
    desc: 'ML concepts, perceptron implementation, neural networks from scratch, and training algorithms.', color: '#42a5ff' },
  { id: '18-digit-recognition', num: 18, name: 'Digit Recognition', level: 'expert', dir: '18-digit-recognition',
    desc: 'MNIST dataset, image processing in C, building a digit recognizer, and optimization techniques.', color: '#ff8c42' },
  { id: '19-scientific-computing', num: 19, name: 'Scientific Computing', level: 'expert', dir: '19-scientific-computing',
    desc: 'Numerical methods, matrix operations, molecular dynamics simulations, and physics simulations.', color: '#b388ff' },
  { id: '20-professional-dev', num: 20, name: 'Professional Development', level: 'expert', dir: '20-professional-dev',
    desc: 'Build systems (Make, CMake), unit testing, code style, profiling, optimization, and version control.', color: '#ff6b9d' }
];

const LEVELS = [
  { id: 'beginner', name: 'Beginner', range: 'Modules 1-5', desc: 'Start here if you are new to programming. Learn the fundamentals of C syntax, control flow, and basic data structures.' },
  { id: 'intermediate', name: 'Intermediate', range: 'Modules 6-10', desc: 'Master pointers, memory management, structures, file I/O, and the preprocessor.' },
  { id: 'advanced', name: 'Advanced', range: 'Modules 11-15', desc: 'Dive into complex data structures, debugging, GUI programming, and game development.' },
  { id: 'expert', name: 'Expert', range: 'Modules 16-20', desc: 'Explore networking, machine learning, scientific computing, and professional development practices.' }
];

async function fetchFromGitHub(path) {
  const url = `${RAW_BASE}/${path}`;
  const resp = await fetch(url);
  if (!resp.ok) throw new Error(`HTTP ${resp.status}: ${path}`);
  return resp.text();
}

const mdRender = (md) => {
  const escape = (t) => t.replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;').replace(/"/g,'&quot;');
  const inline = (t) => t.replace(/`([^`]+)`/g, '<code>$1</code>').replace(/\*\*([^*]+)\*\*/g, '<strong>$1</strong>').replace(/\*([^*]+)\*/g, '<em>$1</em>').replace(/\[([^\]]+)\]\(([^)]+)\)/g, '<a href="$2" target="_blank" rel="noopener">$1</a>');

  const lines = md.split('\n');
  let html = '';
  let inList = false, listType = '', inCode = false;
  for (let i = 0; i < lines.length; i++) {
    let l = lines[i];
    if (l.startsWith('```')) {
      if (inCode) { html += '</code></pre>\n'; inCode = false; }
      else {
        const lang = l.slice(3).trim();
        html += `<pre class="code-block"${lang ? ` data-lang="${escape(lang)}"` : ''}><code>`;
        inCode = true;
      }
      continue;
    }
    if (inCode) { html += escape(l) + '\n'; continue; }

    if (l.startsWith('# ')) { html += `<h1>${inline(l.slice(2).trim())}</h1>\n`; }
    else if (l.startsWith('## ')) { html += `<h2>${inline(l.slice(3).trim())}</h2>\n`; }
    else if (l.startsWith('### ')) { html += `<h3>${inline(l.slice(4).trim())}</h3>\n`; }
    else if (l.startsWith('#### ')) { html += `<h4>${inline(l.slice(5).trim())}</h4>\n`; }
    else if (l.startsWith('- ') || l.startsWith('* ')) {
      const li = l.replace(/^[-*]\s+/, '');
      if (!inList || listType !== 'ul') {
        if (inList) html += `</${listType}>\n`;
        html += '<ul>\n'; inList = true; listType = 'ul';
      }
      html += `  <li>${inline(li)}</li>\n`;
    }
    else if (/^\d+[.)]\s/.test(l)) {
      const li = l.replace(/^\d+[.)]\s+/, '');
      if (!inList || listType !== 'ol') {
        if (inList) html += `</${listType}>\n`;
        html += '<ol>\n'; inList = true; listType = 'ol';
      }
      html += `  <li>${inline(li)}</li>\n`;
    }
    else {
      if (inList) { html += `</${listType}>\n`; inList = false; }
      if (l.startsWith('> ')) {
        html += `<blockquote>${inline(l.slice(2).trim())}</blockquote>\n`;
      } else if (l.startsWith('---')) {
        html += '<hr>\n';
      } else if (l.trim() === '') {
        html += '\n';
      } else {
        if (l.includes('```')) {
          const parts = l.split(/```(\w*)/);
          html += `<p>${inline(parts[0])}`;
          if (parts.length > 1) html += `<code>${escape(parts.slice(1).join(''))}</code>`;
          html += '</p>\n';
        } else {
          html += `<p>${inline(l)}</p>\n`;
        }
      }
    }
  }
  if (inList) html += `</${listType}>\n`;
  if (inCode) html += '</code></pre>\n';
  return html;
};

function getModuleByDir(dir) {
  return MODULES.find(m => m.dir === dir) || null;
}

async function loadHomeModules() {
  const grid = document.getElementById('module-grid');
  if (!grid) return;

  grid.innerHTML = LEVELS.map(level => {
    const mods = MODULES.filter(m => m.level === level.id);
    return `
      <div class="level-card" data-level="${level.id}" onclick="Router.navigate('modules', {module: '${mods[0]?.id}'})" style="animation-delay: ${LEVELS.indexOf(level) * 0.1}s">
        <div class="level-card-header">
          <span class="level-name">${level.name}</span>
          <span class="level-range">${level.range}</span>
        </div>
        <p class="level-desc">${level.desc}</p>
        <div class="level-modules">
          ${mods.map(m => `<span class="module-chip">${m.num}. ${m.name}</span>`).join('')}
        </div>
      </div>
    `;
  }).join('');
}

async function loadModulesPage() {
  const list = document.getElementById('module-list');
  if (!list) return;
  list.innerHTML = '';

  const filter = document.querySelector('.filter-btn.active');
  const level = filter ? filter.dataset.level : 'all';

  const filtered = level === 'all' ? MODULES : MODULES.filter(m => m.level === level);

  filtered.sort((a, b) => a.num - b.num).forEach((mod, i) => {
    const card = document.createElement('div');
    card.className = 'module-card';
    card.style.animationDelay = `${i * 0.05}s`;
    card.innerHTML = `
      <div class="module-card-header">
        <span class="module-num" style="color:${mod.color}">Module ${String(mod.num).padStart(2, '0')}</span>
        <span class="level-range">${mod.level}</span>
      </div>
      <div class="module-name">${mod.name}</div>
      <div class="module-desc">${mod.desc}</div>
    `;
    card.addEventListener('click', () => Router.navigate('modules', { module: mod.id }));
    list.appendChild(card);
  });
}

async function loadModuleDetail(moduleId) {
  const container = document.getElementById('module-content');
  if (!container) return;

  container.innerHTML = `<div class="loading-container"><div class="loader"></div><p>Loading module content from GitHub...</p></div>`;

  const mod = MODULES.find(m => m.id === moduleId);
  if (!mod) {
    container.innerHTML = '<div class="error-container"><h3>Module not found</h3><p>The requested module could not be found.</p></div>';
    return;
  }

  try {
    const readme = await fetchFromGitHub(`${mod.dir}/README.md`);
    let html = mdRender(readme);

    try {
      const files = await (await fetch(`${GITHUB_API}/contents/${mod.dir}`)).json();
      if (Array.isArray(files)) {
        const cFiles = files.filter(f => f.name.endsWith('.c') || f.name.endsWith('.h')).sort((a, b) => a.name.localeCompare(b.name));
        if (cFiles.length > 0) {
          html += '\n<h2>Source Files</h2>\n<p>Click to view or edit any file in the playground:</p>\n<p>';
          cFiles.forEach(f => {
            html += `<a class="code-file-link" href="#" data-file="${f.path}" data-name="${f.name}">
              <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/></svg>
              ${f.name}
            </a>`;
          });
          html += '</p>\n';
        }
        const makefiles = files.filter(f => f.name === 'Makefile' || f.name === 'Makefile.common' || f.name.match(/^Makefile\./));
        if (makefiles.length > 0) {
          html += '\n<h2>Build System</h2>\n<p>Build files available:</p>\n<ul>\n';
          makefiles.forEach(f => html += `  <li><code>${f.name}</code></li>\n`);
          html += '</ul>\n';
        }
      }
    } catch (e) {}

    container.innerHTML = `
      <div class="module-detail-header">
        <h1 style="color:${mod.color}">Module ${String(mod.num).padStart(2, '0')}: ${mod.name}</h1>
        <p class="section-desc" style="text-align:left">${mod.desc}</p>
      </div>
      <div class="module-body">
        ${html}
      </div>
    `;

    container.querySelectorAll('.code-file-link').forEach(link => {
      link.addEventListener('click', (e) => {
        e.preventDefault();
        const file = link.dataset.file;
        const name = link.dataset.name;
        const codeEditorEvent = new CustomEvent('load-file', { detail: { path: file, name } });
        document.dispatchEvent(codeEditorEvent);
        Router.navigate('playground');
      });
    });

    if (typeof Prism !== 'undefined') Prism.highlightAllUnder(container);

  } catch (err) {
    container.innerHTML = `
      <div class="error-container">
        <h3>Failed to load module</h3>
        <p>Could not fetch content from GitHub. ${err.message}</p>
        <p>Try viewing directly: <a href="https://github.com/${GITHUB_OWNER}/${GITHUB_REPO}/tree/main/${mod.dir}" target="_blank">${mod.dir}/</a></p>
      </div>
    `;
  }
}

async function loadRepoStats() {
  try {
    const resp = await fetch(GITHUB_API);
    if (resp.ok) {
      const data = await resp.json();
      const starsEl = document.getElementById('repo-stars');
      const forksEl = document.getElementById('repo-forks');
      if (starsEl) starsEl.textContent = data.stargazers_count ?? '-';
      if (forksEl) forksEl.textContent = data.forks_count ?? '-';
    }
  } catch (e) {}
}

async function loadFileContent(path) {
  try {
    return await fetchFromGitHub(path);
  } catch (err) {
    console.error('Failed to load file:', path, err);
    return null;
  }
}
