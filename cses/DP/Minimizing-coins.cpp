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
vector<int> coins;
int solve(int x){
  if (x == 0)
    return 0;
  if (x < 0)
    return INT_MAX;

  if (dp[x] != -1)
    return dp[x];

  int ans = INF;
  for (auto c: coins){
    ans = min(ans, solve(x - c) + 1);
  }

  return dp[x] = ans;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n, x;
  cin >> n >> x;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++){
    int value; cin >> value;
    coins.pb(value);
  }
  int s = solve(x);
  cout << ((s >= INT_MAX) ? -1: s)  << endl;

  return 0;
}
