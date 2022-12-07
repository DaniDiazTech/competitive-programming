// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int MOD = 1e9 + 7;



int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n, x; cin >> n >> x;
  vector<int> h(n);
  vector<int> s(n);
  
  forn(i,n) cin >> h[i];
  forn(i,n) cin >> s[i];

  vector<vector<int>> dp(n + 1,  vector<int>(x +1, 0));
  for (int i = 0; i < n; i++){
    for (int price = 0; price <= x; price++){
      dp[i + 1][price] = dp[i][price];
      if (price >= h[i])
        dp[i + 1][price] = max(dp[i + 1][price], s[i] + dp[i][price - h[i]]);
    }

  }
  cout << dp[n][x];
}
