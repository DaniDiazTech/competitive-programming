// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, q, m;
  cin >> n >> q >> m;
  vector<ll> a(n), t(n), mn(n);
  for (auto &c: a) cin >> c;
  for (auto &c: t) cin >> c;

  for (int i = 0;i < n; i++){
    mn[i] = t[i];
    if (i > 0) mn[i] = min(mn[i], mn[i - 1]);
  }

  while (q--){
    int i, j; cin >> i >> j;
    i--;j--;
    ll ans = 1e18;

    if (a[i] > a[j] + m){
      int l = 0, r = n;
      while (l + 1 < r){
        int m = (l + r) / 2;
        if (a[m] <= a[j] + m){
          l = m;
        }
        else r = m;
      }
      ans = min(1 + t[j], 2 + mn[l]);
    }
    else{
      ans = 1;
    }

    cout << ans << '\n';
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
