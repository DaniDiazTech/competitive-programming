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
  string x,y; cin >> x >> y;
  int n = x.size(), m = y.size();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++){
    dp[i][0] = i; 
  }
  for (int j = 0 ; j <= m; j++){
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; i++){
    for (int j =1 ; j <= m; j++){
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (x[i -1] != y[j - 1])});
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
