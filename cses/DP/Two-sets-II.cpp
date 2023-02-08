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

const int MAX = 501;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

const int sumn = MAX * (MAX + 1) / 2;
int dp[MAX][sumn];

void solve(){
  int n;
  cin >> n;
  int t = n * (n + 1) / 2;
  if (t & 1){
    cout << 0 << endl;
    return;
  }

  t/=2;

  vector<vector<int>> dp(n, vector<int>(t+1,0));
  dp[0][0] = 1;
  // Only considering up to n -1: Doesn't repeat sets of numbers
  for (int i =1; i < n; i++){
    for (int j = 0 ; j <= t; j++){
      dp[i][j] = (dp[i - 1][j] + (j - i >=0 ? dp[i - 1][j - i]: 0)) % MOD;
    }
  }
  cout << dp[n - 1][t];
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
