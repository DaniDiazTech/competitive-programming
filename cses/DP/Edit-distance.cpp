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

string F, S;
int dp[5010][5010];

int cost(int a, int b){
  return (int)(F[a - 1] != S[b - 1]);
}
int solve(int a, int b){
  // if (a == 0 || b == 0) 
  //   return 0;
  if (dp[a][b] != -1)
    return dp[a][b];
  return dp[a][b] = min({
    solve(a, b - 1) + 1,
    solve(a - 1, b) + 1, 
    solve(a -1, b - 1) + cost(a, b)});
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  cin >> F >> S;
  memset(dp, -1, sizeof(dp));
  // Populate the prefix
  for (int i = 0; i <= (int)F.size(); i++){
    dp[i][0] = i;
  }
  for (int j = 0; j <= (int)S.size(); j++){
    dp[0][j] = j; 
  }
  cout << solve(F.size(), S.size()) << endl;
  // for (int i = 0; i <= F.size(); i++){
  //   for (int j = 0; j <= (int)S.size(); j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}
