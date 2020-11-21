#include <bits/stdc++.h>
using namespace std;

const int N = (1<<20) + 12;
const int inf = 1e9;

int n;
int a[20];
pair<int, int> dp[N][20];

pair<int, int> ds(int msk, int i) {
  if (!msk) return {0, 0};
  if (~dp[msk][i].first) return dp[msk][i];
  auto& res = dp[msk][i];
  res = {inf, inf};
  int pre = msk - (1<<i);
  for (int j = 0; j < n; j++) {
    if ((pre>>j) & 1) {
      auto [x, y] = ds(pre, j);
      if (x > res.first) continue;
      int st = max(y, x + 1 - a[i]);
      int tot = st + a[i];
      st = x + 1;
      if (tot == res.first)
        res.second = min(res.second, st);
      else
        res = {tot, st};
    }
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[1<<i][i] = {a[i], 1};
  }
  int res = inf;
  for (int i = 0; i < n; i++)
    res = min(res, ds((1<<n)-1, i).first);
  cout << res << '\n';
  return 0;
}

