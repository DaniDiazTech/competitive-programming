// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  vector<int> dis(n+ 1, - 1), sz(n + 1, 0);
  dis[1] = 0;
  for (int i =0 ;i  < n - 1; i++){
    int u, v; cin >> u >> v; 
    g[u].push_back(v);
    g[v].push_back(u);
  }

  function<int(int, int)> dfs = [&](int u, int p){
    sz[u] = 1;
    for (auto v: g[u]){
      if (p != v){
        dis[v] = dis[u] + 1;
        sz[u] += dfs(v, u);
      }
    }
    return sz[u];
  };

  dfs(1, -1);

  priority_queue<int> pq;
  for (int i = 1; i<=n; i++){
    // cout << i << " " << dis[i] << " " << sz[i] << endl;
    pq.push(dis[i] - sz[i] + 1);
  }
  ll ans =0;
  for (int i = 0; i < k; i++){
    auto d = pq.top();
    pq.pop();
    ans += d;
  }

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
