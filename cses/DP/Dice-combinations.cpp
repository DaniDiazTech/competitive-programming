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

const int MAX = 1e6 + 10;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int dp[MAX];
int go(int n){
  // Base cases
  if (n  < 0) return 0;
  if (n == 1 || n == 0) return 1;

  // Already calculated
  if (dp[n] != -1) return dp[n];
  return dp[n] = (go(n - 1) + go(n - 2) + go(n - 3) + go(n - 4) + go(n - 5) + go(n - 6)) % MOD;
}

void solve_recursive(){
  int n;
  cin >> n;
  // Turns all the values of the dp to -1
  memset(dp, -1, sizeof(dp));

  cout << go(n) << endl;
}

void solve_iteratively(){
  // Top down
  int n; cin >> n;
  memset(dp, 0, sizeof(dp));
  // Initial state

  dp[0] = 1;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= 6 && i -j >= 0; j++){
      dp[i] += (dp[i - j]) % MOD;
    }
  }
  cout << dp[n] << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  solve_iteratively();
  return 0;
}
