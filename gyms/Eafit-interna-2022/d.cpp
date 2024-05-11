// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n + 1][n + 1];
  ll dp[n + 1][n + 1];
  int mn = -1e9;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (j < i + 1){
        cin >> a[i][j];
      }
      else{
        a[i][j] = mn;
      }
      dp[i][j] = mn;
    }
  }
  for (int i = 0;i < n; i++){

  }
  dp[0][0] = a[0][0];
  for (int i =0 ; i < n; i++){
    for (int j = 0; j < i + 1; j++){
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
    }
  }
  ll ans = mn;
  for (int i = 0; i < n; i++){
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << '\n';
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
