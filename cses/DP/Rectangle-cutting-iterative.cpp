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

const int MAX = 510;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int dp[MAX][MAX];
void solve(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++){
    for (int j= 0; j <= m; j++){
      dp[i][j] = INF;
    }
  }
  for (int i =0 ; i <= n; i++){
    dp[i][i] = 0;
  }

  for (int i =1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      for (int c= 1; c < i; c++){
        dp[i][j] = min(dp[i][j], dp[c][j] + dp[i - c][j] + 1);
      }
      for (int c= 1; c < j; c++){
        dp[i][j] = min(dp[i][j], dp[i][c] + dp[i][j - c] + 1);
      }
    }
  }

  cout << dp[n][m] << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
