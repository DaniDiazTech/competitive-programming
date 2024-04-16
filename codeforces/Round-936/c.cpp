// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 1e5 + 10;
vector<int> g[N];
vector<int> sz(N), depth(N);


int cnt;

int dfs(int u, int p, int l){
  sz[u] = 1;
  depth[u] = l;

  for (auto v: g[u]){
    if (v != p){
      sz[u] += dfs(v, u, l + 1);
    }
  }
  return sz[u];
}

vector<int> parent(N);
vector<int> sze(N);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void make_set(int v) {
  parent[v] = v;
  sze[v] = 1;
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
      if (sze[a] < sze[b])
          swap(a, b);
      parent[b] = a;
      sze[a] += sze[b];
  }
}


void solve(){
  int n, k;
  cin >> n >> k;

  for (int i = 1; i<= n; i++){
    g[i].clear();
    sz[i] = 0;
  }
  for (int i = 1; i< n; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1, -1, 0);

  // for (int i = 1; i <= n; i++){
  //   cout << depth[i] << " ";
  // }
  // cout << endl;
  // queue
  int l = 1, r = n;
  
  while (l + 1 < r){
    int m = (l + r) / 2;
    int cnt = k;


    priority_queue<pair<int,int>> pq;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++){
      pq.push({depth[i], i});
      vis[i] = 0;
      make_set(i);
    }

    while (pq.size()){
      int u = pq.top().second;
      pq.pop();
      vis[u] = 1 ;
      if (u == 1) continue;
      // for (int i = 1; i<= n; i++){
      //   cout << sze[find_set(i)] << " ";
      // }
      // cout << endl;
      if (sze[find_set(u)] >= m){
        if (cnt > 0){
          cnt--;
          continue;
        }
      }

      for (auto v: g[u]){
        if (!vis[v]){
          union_sets(v, u);  
        }
      }
    }

    bool flag = 1;
    // cout << "M: " << m << endl;
    // for (int i = 1; i<= n; i++){
    //   cout << sze[find_set(i)] << " ";
    // }
    // cout << endl;
    for (int i = 1; i<= n; i++){
      flag &= (sze[find_set(i)] >= m);
    }

    if (cnt <= 0 && flag){
      l =m;
    }
    else r = m;

  }
  
  cout << l << endl;
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
