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
    return 1;
  if (x < 0)
    return 0;
  if (dp[x] != -1)
    return 0;
  
  int sum = 0; 
  for (auto c: coins){
    dp[x] = sum = solve(x - c) + sum;
  }
  return sum;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n, x; cin >> n >> x;
  memset(dp, -1, sizeof(dp));
  forn(i,n){
    int v; cin >> v;
    coins.pb(v);
  }

  cout << solve(x) << endl;
  return 0;
}
