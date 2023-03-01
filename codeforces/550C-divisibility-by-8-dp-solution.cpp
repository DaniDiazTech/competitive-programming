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

const int MAX = 105;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

bool dp[MAX][8];
int prev[MAX][8];

void solve(){
  string s;
  int n;
  cin >> s;
  n  = s.size();
  memset(prev, -1, sizeof(prev));
  dp[0][(s[0] - '0') % 8] = true;

  for (int i  = 1; i < n; i++){
    dp[i][(s[i] -  '0') % 8]  = true;

    for (int j = 0; j < 8; j++){
      if (dp[i - 1][j]){
        dp[i][(j* 10 + s[i] - '0') % 8] = true;
        prev[i][(j * 10 + s[i]-'0') % 8] = j;
        dp[i][j]  = true;
        prev[i][j] =  j;
      }
    }
  }
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
