#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> st;
vector<int> vis;
bool poss = true;

void dfs(int u) {
  if (vis[u] > 0) {
    if (vis[u] == 1)
      poss = false;
    return;
  }
  vis[u] = 1;
  for (int v : g[u])
    dfs(v);
  vis[u] = 2;
  st.push_back(u);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  g.resize(n + 1);
  vis.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    dfs(i);
  if (!poss || st.size() != n) {
    cout << "IMPOSSIBLE\n";
  } else {
    reverse(st.begin(), st.end());
    for (int x : st)
      cout << x << '\n';
  }
  return 0;
}

