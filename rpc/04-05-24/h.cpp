// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e4;

vector<pair<int, int>> g[N];

void solve(){
  int n, m;
  cin >> n >> m;
  for (int i = 0;i < m; i++){
    int u, v, w;
    char t;
    cin >> u >> v >> t >> w;
    g[u].push_back({v, w * (t == 'b' ? 1 : -1)});
  } 
  // u, time
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  vector<int> dis(n + 100, INT_MAX);
  pq.push({0, 1});
  dis[1] = 0;

  while (pq.size()){
    auto p = pq.top();
    pq.pop();
    int u = p.second, w = p.first;
    if (w > dis[u]) continue;

    for (auto v: g[u]){
      int to = v.first, len = v.second;
      if (dis[u] + len < dis[to]){
        dis[to] = dis[u] + len;
        pq.push({dis[to], to});
      }
    }
  }

  for (int i = 1; i <= n; i++){
    if (dis[i] < 0){
      cout << i << '\n';
    }
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
