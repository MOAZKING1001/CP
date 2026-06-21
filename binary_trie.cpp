struct Node {
  int cnt {};
};
struct Trie {
  int n {};
  vector<array<int, 2>> adj;
  vector<Node> a;
  Trie() { adj.emplace_back(), a.emplace_back(); }
  void insert(int x) {
    int node = 0;
    for (int i = 31; ~i; i--) {
      int bit = x >> i & 1;
      if (adj[node][bit]) {
        node = adj[node][bit];
        a[node].cnt++;
      } else {
        n++;
        a.emplace_back();
        adj.emplace_back();
        adj[node][bit] = n;
        node = n;
        a[node].cnt++;
      }
    }
  }
  int count(int x) {
    int node = 0, ans = 0;
    for (int i = 31; ~i; i--) {
      int bit = x >> i & 1;
      if (adj[node][bit]) {
        node = adj[node][bit];
      } else {
        node = adj[node][bit];
      }
    }
    return ans;
  }
};