// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;


int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n, m; cin >> n >> m;
  int a[n + 1];
  vector<vector<int>> dp(n + 1, vector<int>(m + 2,0));
  forn(i, n) cin >> a[i];
  if (a[0] == 0)
    for (int j = 1;j <= m; j++) dp[0][j] = 1;
  else
    dp[0][a[0]] = 1;

  for (int i = 1; i < n; i++){
    if (a[i] == 0){
      for (int j = 1; j <= m; j++){
        for (int k = j - 1; k <= j +1; k++){
          dp[i][j] += dp[i - 1][k];
        }
        dp[i][j] %= MOD;
      }
    }
    else{
      for (int k = a[i] - 1; k <= a[i] + 1; k++){
        dp[i][a[i]] += dp[i - 1][k];
      }
      dp[i][a[i]] %= MOD;
    }
  }

  // forn(i,n){
  //   forn(j, m + 2){
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  int ans = 0;
  for (int j = 1; j <= m; j++){
    ans += dp[n - 1][j];
    ans %= MOD;
  }
  cout << ans;
  return 0;
}
