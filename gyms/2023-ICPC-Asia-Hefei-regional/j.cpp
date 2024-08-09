// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

#define pii pair<int, pair<int,int>>


const int INF = INT_MAX;

void solve(){
  int n, m;
  cin >> n >> m;

  vector<pii> edges;

  vector<vector<pair<int,int>>> g(n + 1);

  vector<int> dis1(n + 1, INF), disn(n + 1, INF);

  for (int i = 0;i < m; i++){
    int u, v,w ; cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
    // edges.push_back({w, {v, u}});

    g[u].push_back({w, v});
    g[v].push_back({w, u});
  }

  // precalc
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  dis1[1] = 0;
  pq.push({0, 1});

  while (pq.size()){
    auto p = pq.top();
    pq.pop();
    int u = p.second, d = p.first;
    if (d != dis1[u]) continue;

    for (auto edge: g[u]){
      int v = edge.second, w = edge.first; 
      
      int x = max(w, d);
      if (dis1[v] > x){
        dis1[v] = x;
        pq.push({x, v});
      }
    }
  }

  pq.push({0, n});
  disn[n] = 0;
  while (pq.size()){
    auto p = pq.top();
    pq.pop();
    int u = p.second, d = p.first;
    if (d != disn[u]) continue;

    for (auto edge: g[u]){
      int v = edge.second, w = edge.first; 
      
      int x = max(w, d);
      if (disn[v] > x){
        disn[v] = x;
        pq.push({x, v});
      }
    }
  }

  // for (auto x: dis1) cout << x << " ";
  // cout << endl;
  // for (auto x: disn) cout << x << " ";
  // cout << endl;

  sort(edges.begin(), edges.end());

  int ans = INF;
  for (auto edge: edges){
    int w = edge.first;
    int u = edge.second.first, v = edge.second.second;

    int x  =  min(max(dis1[v], disn[u]),  max(dis1[u], disn[v]));

    if (x <= w){
      ans = min(ans, x + w);
    }
  }

  assert(ans > 0);
  cout << ans << endl;

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
