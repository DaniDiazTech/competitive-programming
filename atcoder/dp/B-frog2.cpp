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

int dp[MAX + 10];
int a[MAX + 10];
int k;
int solve(int i) {
  if (i == 0)
    return 0;
  if (i < 0)
    return INT_MAX;

  if (dp[i] != -1)
    return dp[i];

  int mn = INF;
  for (int j = 1; j <= k; j++){
    if (j > i)
      break;
    mn = dp[i] = min(solve(i - j) + abs(a[i] - a[i - j]), mn);
  }
  return mn;
}

int32_t main() {
  fastInp;
#if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n; cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    a[i] = x;
  }

  cout << solve(n - 1);
  return 0;
}
