// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const ll inf = 1e17;
const int M = 50010;
void solve(){
  ll m, x;
  cin >> m >> x;
  vector<pair<ll,ll>> h(m);
  for (auto &c: h) cin >> c.first >> c.second;
  vector<ll> dp(M, inf);
  dp[0] = 0;
  ll mx = 0;
  for (ll i = 0;i < m; i++){
    for (ll j = mx;j >= 0 ; j--){
      if (i * x - dp[j] >= h[i].first){
        ll &l = dp[j + h[i].second];
        l = min(l, dp[j] + h[i].first);
      } 
    }
    mx += h[i].second;
  }   
  int ans = 0;
  for (int i = 0;i < M; i++){
    if (dp[i] < inf) ans = i;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
