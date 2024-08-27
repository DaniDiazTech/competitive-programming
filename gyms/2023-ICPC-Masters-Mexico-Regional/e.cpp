// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const ll inf = 1e18;

void solve(){
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;t--;
  vector<vector<pair<ll,int>>> g(n);

  for (int i =0 ;i < m; i++){
    int u, v, c; cin >> u >> v >> c;
    u--;v--;
    g[u].push_back({-c, v});
  }
  
  vector<bool> vis(n);
  function<void(int)> dfs = [&](int u){
    vis[u] = 1 ;
    for (auto edge: g[u]){
      int v = edge.second;
      if (!vis[v]){
        dfs(v);
      }
    }
  };

  dfs(s);

  if (!vis[t]){
    cout << "Bad trip" << endl;
    return;
  }


  vector<ll> cost(n);
  for (int i = 0;i < n; i++){
    cin >> cost[i];
  }
  // maximize distance
  // Make n - 1 dijkstras
  vector<ll> dis(n, -inf), freq(n);
  priority_queue<pair<ll,int>> pq;
  pq.push({0, s});
  dis[s] = 0;
  
  while (pq.size()){
    auto p = pq.top();
    pq.pop();
    ll d = p.first, u = p.second;
    if (d < dis[u]) continue;
    if (freq[u] >= n + 1){
      break;
    }
    freq[u]++;

    for (auto edge: g[u]){
      ll x = edge.first, v = edge.second;
      ll now = x + d + cost[v];
      if (dis[v] < now){
        dis[v] = now;
        pq.push({now, v});
      }
    }
  }

  for (int i = 0;i < n; i++){
    if (freq[i] >= n){
      vis.assign(n, 0);
      dfs(i);
      if (vis[t]){
        cout << "Money hack!" << endl;
        return;
      }
    }
  }
  
  cout << dis[t] << endl;

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
