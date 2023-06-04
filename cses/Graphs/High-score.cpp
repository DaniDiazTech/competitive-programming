// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

int vis[4000], vis2[4000];
vector<int> g[4000], g2[4000];
int dis[4000 + 10];
void dfs(int u){
  vis[u] =1;
  for (auto v: g[u]){
    if (!vis[v])
      dfs(v);
  }
}
void dfs2(int u){
  vis2[u] =1;
  for (auto v: g2[u]){
    if (dis[v] == oo){
      cout << - 1<< endl;
      exit(0);
    }
    if (!vis2[v])
      dfs2(v);
  }
}

void solve(){
  int n,m;
  cin >> n >> m;
  fill(dis, dis + n + 5, ooo / 2);
  vector<vector<int>> edges;

  fore(i,0,m){
    vector<int> v(3); cin >> v[0] >> v[1] >> v[2];
    g[v[0]].pb(v[1]);
    g2[v[1]].pb(v[0]);
    edges.pb(v);
  }
  dfs(1);

  dis[1] = 0;
  // Bellman ford algorithm
  for (int i = 0; i < n - 1; i++){
    for (auto e: edges){
      if (vis[e[0]])
        dis[e[1]] = max(dis[e[1]], dis[e[0]] + e[2]); 
    }
  }
  // for (int i =0 ;i < n; i++) cout << dis[i + 1] << endl;;
  // Perform bellman ford twice
  for (int i = 0; i < n - 1; i++){
    for (auto e: edges){
      if (dis[e[1]] < dis[e[0]] + e[2] && vis[e[0]] && dis[e[0]] != oo){
        // Found cycle
        dis[e[1]] = oo;
      }
    }
  }
  dfs2(n);
  cout << dis[n] << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
