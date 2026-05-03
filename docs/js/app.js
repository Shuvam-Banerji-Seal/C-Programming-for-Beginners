document.addEventListener('DOMContentLoaded', () => {
  Router.init();
  loadHomeModules();

  const navToggle = document.querySelector('.nav-toggle');
  const navLinks = document.querySelector('.nav-links');

  if (navToggle) {
    navToggle.addEventListener('click', () => {
      const open = navLinks.classList.toggle('open');
      navToggle.setAttribute('aria-expanded', open);
    });
  }

  document.querySelectorAll('.nav-link').forEach(link => {
    link.addEventListener('click', (e) => {
      navLinks?.classList.remove('open');
      if (navToggle) navToggle.setAttribute('aria-expanded', 'false');
      const page = link.dataset.nav;
      if (page) Router.navigate(page);
    });
  });

  document.querySelectorAll('.filter-btn').forEach(btn => {
    btn.addEventListener('click', () => {
      document.querySelectorAll('.filter-btn').forEach(b => b.classList.remove('active'));
      btn.classList.add('active');
      loadModulesPage();
    });
  });

  const backBtn = document.getElementById('back-to-modules');
  if (backBtn) {
    backBtn.addEventListener('click', () => Router.navigate('modules'));
  }

  const scrollBtn = document.createElement('button');
  scrollBtn.className = 'back-to-top';
  scrollBtn.innerHTML = '<svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M18 15l-6-6-6 6"/></svg>';
  scrollBtn.setAttribute('aria-label', 'Scroll to top');
  document.body.appendChild(scrollBtn);

  window.addEventListener('scroll', () => {
    scrollBtn.classList.toggle('visible', window.scrollY > 400);
  });

  scrollBtn.addEventListener('click', () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  });

  initEditor();
  loadRepoStats();

  console.log(`%c C/&gt; Course `, 'background:#00ff88;color:#000;font-size:14px;font-weight:bold;padding:4px 8px;border-radius:4px;font-family:monospace');
  console.log('%c Learn C programming: https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners', 'color:#888');
});
