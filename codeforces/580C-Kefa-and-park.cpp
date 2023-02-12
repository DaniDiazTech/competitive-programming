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
 
const int MAX = 1e5 + 10;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;
 
vector<int> g[MAX];
bool b[MAX + 1];
int vis[MAX];
int mx, ans = 0;
 
void dfs(int i, int parent , int k){
  if (k > mx || vis[i]) return;
  int ok = 1;
  vis[i] = true;
  for (auto x: g[i]){
    // If doesn't have more nodes to visit, but its parent, then ok remains 1
    if (x != parent) ok = 0;
    dfs(x, i, (k * b[x]) + b[x]);
  }
  ans += ok;
}
 
void solve(){
  int n;
  cin >> n >> mx;
  for (int i = 1;i <= n; i++) cin >> b[i];
 
  for (int i = 1; i < n; i++){
    int x, y; cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(1, -1, b[1]);
  cout << ans << endl;
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