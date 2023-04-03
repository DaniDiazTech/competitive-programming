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

const int MAX = 510;
const int MIN = -MAX;
const int INF = LLONG_MAX / 2;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

// Floyd Warshall's
// DP on graphs basically
// Use intermediate states to build shortest paths
// Adjacency matrix
// Weight of edge (i, j)
int adj[MAX][MAX];

void solve(){
  // Nodes, Edges, Queries
  int n, m, q;
  cin >> n >> m >> q;

  forn(i,MAX){
    forn(j, MAX){
      if (i != j)
        adj[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    adj[a][b] = min(c, adj[a][b]);
    adj[b][a] = min(c, adj[b][a]);
  }

  // Floyd warshall
  for (int k = 1; k < n + 1; k++){
    for (int i = 1; i < n + 1; i++){
      for (int j = 1; j < n + 1; j++){
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }

  while (q--){
    int i, j; cin >> i >> j;
    cout << (adj[i][j] == INF ? -1: adj[i][j]) << endl;
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
