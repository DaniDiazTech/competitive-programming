// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int MAX = 1e6;


ll dis[MAX];
vector<int> g[MAX];

int dfs(int u, int par){
  int cnt = 0;
  for (auto x: g[u]){
    if (x != par){
      dis[u] += dfs(x, u);    
      cnt++;
    }
  }
  if (cnt == 0){
    // leaf
    return dis[u] = 1;
  }
  return dis[u];
}

void solve(){
  int n;
  cin >> n;
  for (int i = 1; i<= n+ 1; i++) g[i].clear(), dis[i] = 0;
  for (int i = 0; i < n - 1; i++){
    int a, b; cin >>a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, -1);
  int q; cin >> q;
  while (q--){
    int x, y; cin >> x >> y;
    cout << dis[x] * dis[y] << '\n';
  }
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
