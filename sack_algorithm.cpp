int big[N], sz[N];
void dfsSize(int node, int par) {
  sz[node] = 1;
  int mx = 0, x = -1;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    dfsSize(child, node);
    sz[node] += sz[child];
    if (sz[child] > mx) {
      mx = sz[child];
      x = child;
    }
  }
  big[node] = x;
}
void dfs(int node, int par, bool keep) {
  int b = big[node];
  for (auto &child : adj[node]) {
    if (child == par || child == b) continue;
    dfs(child, node, false);
  }
  auto add = [&](int x) {
    // add node x
  };
  if (~b) {
    dfs(b, node, true);
    swap(a[node], a[b]);
  }
  a[node].push_back(node);
  add(node);
  for (auto &child : adj[node]) {
    if (child == par || child == b) continue;
    for (auto &x : a[child]) {
      a[node].push_back(x);
      add(x);
    }
  }
  {
    // get node's answer
  }
  if (keep) return;
  for (auto &x : a[node]) {
    // remove node x
  }
}