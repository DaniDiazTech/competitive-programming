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

int a[MAX][3];
int dp[MAX][3];
int n;
int solve(int i, int j){
  if (n == i)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];
  
  int mx = 0;
  for (int k = 0; k < 3; k++){
    if (k != j)
      mx = dp[i][j] = max(mx, solve(i + 1, k) + a[i][j]);
  }
  return dp[i][j];
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  int ans = 0;
  for (int i = 0; i < 3; i++){
    ans = max(ans, solve(0, i));
  }
  cout << ans << endl;

  return 0;
}
