#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll ma = 0, res = 0;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll ctr = 0;
      while (n % i == 0) {
        n /= i;
        ctr++;
      }
      if (ctr > ma) {
        ma = ctr;
        res = i;
      }
    }
  }
  if (n > 1) {
    if (ma == 0)
      res = n;
  }
  cout << res << '\n';
  return 0;
}

