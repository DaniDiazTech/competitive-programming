// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

  
vector<pair<ll,ll>> a;

const int W = 1e5 + 10;
const ll inf = 1e18;
ll n, w;

void solve(){
  vector<ll> dp(W, inf);
  dp[0] = 0;
  int mx = 0 ;
  for (int i =0 ;i < n; i++){
    for (int j = mx; j >= 0; j--){
      if (dp[j] + a[i].first <= w){
        dp[j + a[i].second] = min(dp[j + a[i].second], dp[j] + a[i].first);
      }
    }
    mx += a[i].second;
  }
  int ans = 0;
  for (int i =0 ;i < W; i++){
    if (dp[i] <= w){
      ans = i;
    }
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
  // cin >> tc;

  cin >> n >>  w;
  for (int i =0;i < n; i++){
    int x, y; cin >> x >> y;
    a.push_back({x, y});
  }
  solve();
}
