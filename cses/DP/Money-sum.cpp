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

bool dp[105][(int)1e5 + 10];

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  int a[n];
  int m = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    m += a[i]; 
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (dp[i - 1][j]){
        dp[i][j] = true;
        dp[i][j + a[i - 1]] = true;
      }
    }
    dp[i][a[i - 1]] = true;
  }

  // answer
  vector<int> v;
  for (int i = 1; i <= m; i++){
    if (dp[n][i])
      v.pb(i);
  }
  cout << v.size() << endl;
  for (auto i: v){
    cout << i << " ";
  }
  cout << endl;

  // print dp
  // for (int i = 0; i <= n; i++){
  //   for (int j =0 ; j <= m; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}
