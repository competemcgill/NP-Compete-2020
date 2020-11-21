#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6 + 12;

int n, q;
int a[MN], ts[MN];
int ini, rt;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    string cmd;
    cin >> cmd;
    if (cmd[0] == 'S') {
      int idx, x;
      cin >> idx >> x;
      a[idx] = x;
      ts[idx] = i;
    } else if (cmd[0] == 'R') {
      cin >> ini;
      rt = i;
    } else {
      int idx;
      cin >> idx;
      if (rt >= ts[idx])
        cout << ini << '\n';
      else
        cout << a[idx] << '\n';
    }
  }
  return 0;
}

