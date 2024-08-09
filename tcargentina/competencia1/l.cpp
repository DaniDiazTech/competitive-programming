// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  vector<int> g[n];
  vector<int> color(n, - 1);
  // 0 if directed, 1 if in the other direction
  vector<pair<int,int>> adj;


  for (int i = 0;i < m; i++){
    int u , v; cin >> u >> v;  
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    adj.push_back({u,v});
  }

  bool f = 1;
  
  function<void(int, int)> dfs = [&](int u, int col){
    if (!f) return;
    color[u] = col;
    for (auto v: g[u]){
      if (color[v] == col){
        f = 0;
        return;
      }
      if (color[v] != -1) continue;
      dfs(v, !col);
    }
  };

  dfs(0, 0);

  if (f){
    cout << "YES" << endl;
    for (int i = 0;i < m; i++){
      cout << color[adj[i].first];
    }
    cout << endl;
  }
  else{
    cout << "NO" << endl;
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
