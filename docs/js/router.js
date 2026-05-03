const Router = {
  current: 'home',
  params: {},

  init() {
    this.handleRoute();
    window.addEventListener('popstate', () => this.handleRoute());
  },

  handleRoute() {
    const params = new URLSearchParams(window.location.search);
    const page = params.get('page') || 'home';
    const moduleId = params.get('module');
    this.navigate(page, { module: moduleId, replace: true });
  },

  navigate(page, opts = {}) {
    const { module: moduleId, replace } = opts;
    this.current = page;
    this.params = { module: moduleId };

    document.querySelectorAll('.page').forEach(p => p.classList.remove('active'));
    document.querySelectorAll('.nav-link').forEach(l => l.classList.remove('active'));

    const pageEl = moduleId ? document.getElementById('page-module-detail') : document.getElementById(`page-${page}`);
    if (pageEl) pageEl.classList.add('active');

    const navLink = document.querySelector(`.nav-link[data-nav="${page}"]`);
    if (navLink) navLink.classList.add('active');

    document.querySelector('#app').scrollTop = 0;
    window.scrollTo(0, 0);

    const pageMap = { home: '/', modules: '/', playground: '/', about: '/' };
    let url = pageMap[page] || '/';
    if (page !== 'home') {
      const sp = new URLSearchParams();
      sp.set('page', page);
      if (moduleId) sp.set('module', moduleId);
      url = '?' + sp.toString();
    }

    if (!replace) {
      history.pushState({ page, module: moduleId }, '', url);
    }

    if (page === 'modules' && typeof loadModulesPage === 'function') loadModulesPage();
    if (page === 'home' && typeof loadHomeModules === 'function') loadHomeModules();
    if (moduleId && typeof loadModuleDetail === 'function') loadModuleDetail(moduleId);
    if (page === 'about' && typeof loadRepoStats === 'function') loadRepoStats();
  }
};
