// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

vector<pii> g[MAX];
// From  starting point
vector<int> dis(MAX, INF);

void solve(){
  int n, m;
  cin >> n  >> m;
  forn(i,m){
    int a, b, c; cin >> a >> b >> c;
    g[a].pb({b, c});
  }
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 1});
  dis[1] = 0;

  // Dijkstra's algorithm
  while (!pq.empty()){
    pii front = pq.top();
    pq.pop();
    int u = front.ss, d = front.ff;
    if (d > dis[u]) continue;

    for (auto  v: g[u]){
      if (dis[u] + v.ss < dis[v.ff]){
        dis[v.ff] = dis[u] + v.ss;
        pq.push({dis[v.ff], v.ff});
      }
    }
  }

  FOR(i, 1, n + 1){
    cout << dis[i] << " ";
  }
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
