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

vector<int> g[MAX];
int vis[MAX];
int par[MAX];

// Returns node to start to reconstruct if cycle is found
int dfs(int u){
  int ans = -1;
  vis[u] = 2;
  for (auto v: g[u]){
    if (ans != -1) break;
    if (vis[v] == 1 || v == par[u]){
      continue;
    }
    par[v] = u;
    if (vis[v] == 2){
      // Cycle
      vis[u] = 1;
      ans = v;
      break;
    }
    ans = dfs(v);
  }
  vis[u] = 1;
  return ans;
}



void solve(){
  int n, m;
  cin >> n >> m;
  forn(i,m){
    int a, b; cin >> a >>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int ans = -1;
  for (int i = 1; i<= n; i++){
    if (vis[i] == 0){
      ans = dfs(i);
      if (ans != -1){
        break;
      }
    }
  }
  if (ans == -1){
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  vector<int> path;
  path.pb(ans);
  int p = par[ans];
  while (p != ans){
    path.pb(p);
    p = par[p];
  }
  path.pb(ans);
  cout << path.size() << endl;
  for (auto x: path) cout << x << " ";
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
