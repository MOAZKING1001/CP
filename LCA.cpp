struct LCA {
  int n, lg;
  vector<vector<int>> up;
  vector<int> dep;
  LCA() { }
  void dfs(vector<vector<int>> &adj, int node, int u) {
    for (auto &child : adj[node]) {
      if (child == u) continue;
      dep[child] = 1 + dep[node];
      up[child][0] = node;
      for (int i = 1; i <= lg; i++) {
        up[child][i] = up[up[child][i - 1]][i - 1];
      }
      dfs(adj, child, node);
    }
  }
  LCA(vector<vector<int>> &adj, int rt) {
    n = (int)adj.size();
    lg = __lg(n) + 1;
    dep = vector<int>(n + 1);
    up = vector<vector<int>>(n + 1, vector<int>(lg + 1));
    dfs(adj, rt, -1);
  }
  int kth_anc(int u, int k) {
    if (k > dep[u]) return -1;
    for (int i = lg; i >= 0; i--) {
      if (k >> i & 1) {
        u = up[u][i];
      }
    }
    return u;
  }
  int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    u = kth_anc(u, k);
    if (u == v) return u;
    for (int i = lg; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }
};