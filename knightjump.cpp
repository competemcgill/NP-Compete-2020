#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int n;
char s[112][112];
int step[112][112];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  memset(step, -1, sizeof(step));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'K') {
        queue<pair<int,int>> q;
        step[i][j] = 0;
        q.push({i, j});
        while (!q.empty()) {
          auto [ux, uy] = q.front();
          q.pop();
          for (int t = 0; t < 8; t++) {
            int vx = ux + dx[t];
            int vy = uy + dy[t];
            if (vx < 0 || vx >= n) continue;
            if (vy < 0 || vy >= n) continue;
            if (s[vx][vy] != '.' || step[vx][vy] != -1) continue;
            step[vx][vy] = step[ux][uy] + 1;
            q.push({vx, vy});
          }
        }
        cout << step[0][0] << '\n';
        return 0;
      }
    }
  }
  return 0;
}

