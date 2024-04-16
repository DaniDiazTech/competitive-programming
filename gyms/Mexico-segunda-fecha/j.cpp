// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 1e6;

int n, m, q;
vector<int> g[N];
vector<int> vis;
int node;


const int N = 1e6;

int parent[N];
int rank_dsu[N];

// Finds representative of DSU
int find_set(int v) {
  return parent[v] = (v == parent[v] ? v : find_set(parent[v]));
}

void make_set(int v){
  parent[v] = v;
  rank_dsu[v] = 0;
}

void union_set(int u, int  v){
  u = find_set(u);
  v = find_set(v);
  if (u != v){
    // Add tree of lower rank_dsued node to the higher one
    if (rank_dsu[v] > rank_dsu[u])
      swap(u, v); 

    parent[v] = u;
    if (rank_dsu[v] == rank_dsu[u])
      rank_dsu[u]++;
  }
}

void dfs(int u, int p){
  vis[u] = p;
  for (auto v: g[u]){
    if (!vis[v]){
      dfs(v, u);
    }
    else{
      if (v != p){
        // Found cycle
        // Create a new node with connections to all nodes not in cycle.
        node++;
      }
    }
  }
}


void solve(){
  cin >> n >> m >> q;
  node = n + 1;
  for (int i = 0;i < m; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }


  while (q--){
    int s, e; cin >> s >> e;
    // Answer query
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
