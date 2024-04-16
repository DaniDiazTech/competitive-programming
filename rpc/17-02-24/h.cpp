// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 200;

vector<pair<int,ll>> g[N];
vector<set<int>> p(N);
vector<bool> vis(N);
int n, m , a, b;

ll dfs(int u){

  ll x = 0;
  vis[u] = 1;

  for (auto v: g[u]){
    if (p[u].count(v.second)){
      x += v.first;
      x += dfs(v.second);
      p[u].erase(v.second);
    }
  }
  return x;
}

void solve(){
  // n m a b
  cin >> n >> m >> a >> b;

  ll ans = 0;

  for (int i = 0;i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    g[a].push_back({c, b});
    g[b].push_back({c, a});
    ans += c;
  }

    // {distance, vertex}
  priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;

  vector<ll> d(n + 1, 1e10);

  pq.push({0, a});
  d[a] = 0;
  

  while (!pq.empty()){
    auto pr = pq.top();
    pq.pop();

    ll dis = pr.first, u = pr.second;
    // cout << u << " " << dis << " " << d[u] << endl;;

    // already marked u
    if (dis > d[u]) continue;

    for (auto edge: g[u]){
      int v = edge.second; 
      ll x = edge.first + d[u];

      if (x <= d[v]){
        // found better path
        if (x < d[v]){
          p[v].clear();
        }
        d[v] = x;

        p[v].insert(u);
        pq.push({d[v], v});
      }
    }
  }

  // for (int i = 1; i <= n; i++){
  //   cout << i << ", DIS:  " << d[i] << ": ";
  //   for (auto x: p[i]) cout << x << " ";
  //   cout << endl;
  // }

  ans -= dfs(b);

  cout << ans << '\n';

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
