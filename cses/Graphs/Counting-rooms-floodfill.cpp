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

const int MAX = 1010;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;


char a[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j, int n, int m){
  if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.')
    return true;
  return false;
}

int dfs(int i, int j, int n, int m){
  if (!valid(i, j, n, m) || vis[i][j]) return 0;
  vis[i][j] = true;
  dfs(i + 1, j, n, m);
  dfs(i - 1, j, n, m);
  dfs(i, j + 1, n, m);
  dfs(i, j - 1, n, m);
  return 1;
}

void solve(){
  int n, m;  
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j =0 ; j < m; j++)
      cin >> a[i][j];
  int ans = 0; 

  for (int i = 0; i < n; i++){
    for (int j = 0 ; j < m ; j++){
      if (vis[i][j] != true){
        ans += dfs(i, j, n, m);
      }
    }
  }
  cout << ans <<  endl;
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
