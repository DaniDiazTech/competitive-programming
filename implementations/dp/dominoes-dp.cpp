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

// int arr[MAX];
int dp[500];

int go(int n){
  // Already calculated
  if (dp[n] != -1) return dp[n];
  // Base cases
  if (n == 0 || n == 1) return 1;
  return dp[n] = (go(n-1)  + go(n - 2)) % MOD;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;
  // Fills the numbers with the specified value
  memset(dp, -1, sizeof dp);
  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    int n = 4;
    cout << go(n) << endl;
  }
  return 0;
}
