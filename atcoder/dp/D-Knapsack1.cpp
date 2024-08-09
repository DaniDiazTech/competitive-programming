// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
  
vector<pair<int,ll>> a;

const int W = 1e5 + 10;
const ll inf = 1e18;
int n, w;

// 200ms
void solve(){
  ll dp[n + 1][W];
  memset(dp, -1, sizeof dp);
  function<ll(int, int)> go = [&](int i, int j){
    if (j > w) return -inf;
    if (i == n) return 0ll;
    auto &x = dp[i][j];
    if (x != -1) return x;
    return x = max(go(i + 1, j), go(i + 1, j + a[i].first) + a[i].second);
  }; 

  cout << go(0,0) << endl;
}
// 7ms
void solve2(){
  // Iterative
  // Go over m
  sort(a.begin(), a.end());
  vector<ll> dp(w + 10, -1);
  dp[0] = 0;
  int mx = 0;
  for (int i = 0;i < n; i++){
    for (int j = min(mx, w); j>=0; j--){
      if (a[i].first + j <= w){
        dp[a[i].first + j] = max(dp[a[i].first + j], dp[j] + a[i].second);
      }
    }
    mx += a[i].first; 
  }
  ll ans = 0;
  for (int i =0 ;i <= w; i++){
    ans = max(dp[i], ans);  
  }
  cout << ans << '\n';
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >>  w;
  for (int i =0;i < n; i++){
    int x, y; cin >> x >> y;
    a.push_back({x, y});
  }
  solve2();
}
