// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 1e5 + 10;
vector<int> g[N];
vector<int> sz(N);

int dfs(int u, int p){
  sz[u] = 1;

  for (auto v: g[u]){
    if (v != p){
      sz[u] += dfs(v, u);
    }
  }
  return sz[u];
}

void solve(){
  int n, k;
  cin >> n >> k;

  for (int i = 1; i<= n; i++){
    g[i].clear();
    sz[i] = 0;
    if (i == n) continue;
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1, -1);

  // queue

  int l = 1, r = n;
  
  while (l + 1 < r){
    int m = (l + r) / 2;

    bool f= 0;
    int cnt = k;
    vector<int> cursz(n + 1);
    for (int i =1 ;i <= n; i++){
      cursz[i] = sz[i];
    }
    // u, size component
    queue<pair<int, int>> q;
    q.push({1, sz[1]});

    while (q.size()){
      int u = q.front().first, x = q.front().second; 
      q.pop();
      if (cnt == 0) continue;
      
      for (auto v: g[u]){
        if (sz[v] >= m && x - sz[v] >= m){
          // perform edge cutting
          cnt--;  
          x -= sz[v];
          q.push();
        } 
      }
    }

    if (cnt == 0) l = m;
    else r = m;
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
