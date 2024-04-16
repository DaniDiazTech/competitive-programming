// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1010;
const ll inf = 1e18;

vector<pair<int,int>> g[N];


void solve(){
  int n, m;
  cin >> n >> m;
  vector<ll> dis(n + 1, inf), mn(n + 1, inf);
  vector<ll> s(n + 1);
  // clean
  for (int i = 1;i <= n; i++){
    g[i].clear();
  }
  for (int i =0 ;i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
  }
  for (int i = 1;i <= n; i++) cin >> s[i];

  priority_queue<pair<pair<int,int>, int>, vector< pair<pair<int,int>, int>  >, greater< pair< pair<int,int>, int> > > pq;

  dis[1] = 0;
  mn[1] = s[1];

  pq.push({{0, s[1]}, 1});

  while (pq.size()){
    auto p = pq.top();
    pq.pop();
    
    ll w = p.first.first, mnb = p.first.second, u = p.second;

    if (dis[u] < w && mn[u] < mnb) continue;

    for (auto pv: g[u]){
      ll v = pv.first, wv = pv.second;
      ll d = wv * min(s[u], mnb) + dis[u];
      dis[v] = min(dis[v], d);
      mn[v] = min(mn[v], mnb);
      pq.push({{d, mnb}, v});
    }
  }

  cout << dis[n] << '\n';
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
