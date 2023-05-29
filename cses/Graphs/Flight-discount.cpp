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

const int MAX = 2 * 1e5 + 1;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

vector<pii> g[MAX];
int dis[MAX][2];

void solve(){
  int n, m;
  cin >> n >> m;
  for (int i =0 ; i < m; i++){
    int a,b,c; cin >> a >> b >> c;
    g[a].pb({c, b}); 
  }
  fore(i, 0, MAX) dis[i][0] = oo, dis[i][1] = oo;

  // Modified dijkstra
  priority_queue<vector<int>> pq;
  // V[2] = used power?
  pq.push({0, 1, 0});
  dis[1][0] = 0;
  dis[1][1] = 0;

  while (!pq.empty()){
    vector<int> v = pq.top(); pq.pop();
    int u = v[1], used = v[2], current = -v[0]; 
    if (current > dis[u][used]) {
      continue;
    }
    for (auto x: g[u]){
      int w= x.ff, node = x.ss;
      if (!used){
        if (dis[node][1] > current + w / 2){
          // Use coupon code
          dis[node][1] = current + w / 2;
          pq.push({-dis[node][1], node, 1});
        }
      }
      if (dis[node][used] > current+ w){
        dis[node][used] = current + w;
        pq.push({-dis[node][used], node, used});
      }
    }

  }
  cout << dis[n][1] << endl;
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
