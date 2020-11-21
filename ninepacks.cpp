#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 12;

int sz[2];
int dp[2][MN];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  for (int t = 0; t < 2; t++) {
    cin >> sz[t];
    dp[t][0] = 0;
    for (int i = 0; i < sz[t]; i++) {
      int x;
      cin >> x;
      for (int j = MN - 1; j >= x; j--) {
        if (dp[t][j-x] == -1) continue;
        if (dp[t][j] == -1)
          dp[t][j] = dp[t][j-x] + 1;
        else
          dp[t][j] = min(dp[t][j], dp[t][j-x] + 1);
      }
    }
  }
  int res = INT_MAX;
  for (int i = 1; i < MN; i++) {
    if (dp[0][i] == -1 || dp[1][i] == -1)
      continue;
    res = min(res, dp[0][i] + dp[1][i]);
  }
  if (res == INT_MAX)
    cout << "impossible\n";
  else
    cout << res << '\n';
  return 0;
}

