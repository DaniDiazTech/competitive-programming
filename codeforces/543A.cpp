// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int n, m, b; 
const int N = 510;

// Two column DP
int dp[2][N][N];

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  cin >> n >> m >> b >> mod;
  vector<int>a(n); 
  for (auto &x: a)cin>>x;
  memset(dp, 0, sizeof(dp));

  // i ->pos
  // j -> val
  // k -> bugs
  dp[1][0][0] = 1;
  
  // 500 * 500 * 500
  for (int i = 0;i < n; i++){
    for (int j = 0;j <= m ; j++){
      for (int k = 0; k <= b; k++){
        // Didn't take
        auto &l = dp[i % 2][j][k];
        l = dp[(i + 1) % 2][j][k];
        l += (k - a[i] >= 0 && j - 1 >= 0 ? dp[(i % 2)][j - 1][k - a[i]] : 0);
        l %= mod;
      }
    } 
  }
  // j = m
  // k <= b
  ll ans = 0;
  for (int k = 0; k <= b; k++){
    ans += dp[(n + 1) % 2][m][k];
    ans %= mod;
  }
  cout << ans << endl;


}
