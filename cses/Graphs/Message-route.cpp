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

vector<int> G[MAX];
bool vis[MAX];
int dis[MAX];
int parent[MAX];

// Find shortest path in an unweighted graph
// Reconstruct that route
void solve(){
  int n, m;
  cin >> n >> m;
  queue<int> q;

  forn(i,m){
    int a, b; cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
  }

  q.push(1);
  vis[1] = 1;
  dis[1] = 1;
  while (!q.empty()){
    int u = q.front();
    q.pop();
    if (u == n)
      break;
    for (auto v: G[u]){
      // cout << "Adj: " << v << " ";
      if (vis[v]) continue;
      dis[v] = dis[u] + 1;
      parent[v] = u;
      vis[v] = 1;
      q.push(v);
    }
  }
  if (!vis[n]){
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  vector<int> path;
  int p = n;
  while (p != 0){
    path.pb(p);
    p = parent[p];
  }
  cout << dis[n] << endl;
  for (int i = path.size() - 1; i >= 0; i--){
    cout << path[i] << " ";
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
