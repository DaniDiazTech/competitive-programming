// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a, b; cin >> a >> b;
  vector<int> g[n + 1];
  vector<int> dis(n + 1, -1), parent(n + 1, -1);
  for (int i = 0;i < n  -1 ; i++){
    int u, v; cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  // Par
  // u, par
  queue<pair<int,int>> q;
  q.push({a, -1});
  dis[a] = 0;
  while (q.size()){
    auto p = q.front();
    q.pop();
    int u = p.first, par = p.second;
    for (auto v: g[u]){
      if (v != par){
        q.push({v, u});
        dis[v] = dis[u] + 1;
        parent[v] = u;
      }
    }
  }
  int c = (dis[b] + 1) / 2;
  int bu = b;

  while (c--){
    bu = parent[bu];
  }
  vector<int> disb(n + 1, - 1), parb(n + 1, -1); 
  q.push({bu, -1});
  disb[bu] = 0;
  while (q.size()){
    auto p = q.front();
    q.pop();
    int u = p.first, par = p.second;
    for (auto v: g[u]){
      if (v != par){
        q.push({v, u});
        disb[v] = disb[u] + 1;
        parb[v] = u;
      }
    }
  }

  int mx = 0;
  for (int i = 1; i <= n; i++){
    mx = max(disb[i], mx);
  }

  int ans = 2 * (n - 1) + (dis[b] & 1) - mx + (dis[b]) / 2;

  cout << ans << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
