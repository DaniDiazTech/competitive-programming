// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 50002, M = 501;

vector<int> g[N];
vector<int> p(N);
vector<vector<int>> d(N, vector<int>(M));
int n, k;

void dfs(int u, int par){
  p[u] = par;
  for (auto v: g[u]){
    if (v != par){
      dfs(v, u);
    }
  }
}


void solve(){
  cin >> n >> k;
  
  for (int i =0 ;i < n - 1; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, -1);

  for (int u = 1; u<= n ; u++){
    d[u][0] = 1;
    int x = p[u];
    int j = 1;
    while (x != -1 && j <= k){
      d[x][j]++;
      x = p[x];
      j++;
    }
  }


  // for (int i = 1; i <= n; i++){
  //   for (int j = 0; j <= k; j++){
  //     cout << d[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // Dp

  ll ans = 0;

  for (int v = 1; v <= n; v++){
    ans += d[v][k];

    ll s = 0;
    for (auto u: g[v]){
      if (u == p[v]) continue;
      for (int j = 1; j <= k - 1; j++){
        s += (d[u][j - 1]) * (d[v][k - j] - d[u][k - j - 1]); 
        // cout <<"V: " <<  v << " U:  " << u << " " << d[u][j - 1] << " "  << d[v][k - j] - d[u][k - j - 1] << endl;
      }
    }
    ans += s / 2;
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
