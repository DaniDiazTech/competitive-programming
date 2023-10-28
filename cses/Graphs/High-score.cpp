// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 3000;
const ll inf = 1e15;

vector<pair<ll,int>> g[N];
vector<int> g2[N];
bool vis[N];

set<int> possible;

void dfs(int u){
  vis[u] = 1;
  possible.insert(u);
  for (auto v: g2[u]){
    if (vis[v]) continue;
    dfs(v);
  }
}





void solve(){
  int n, m;

  cin >> n >> m;

  for (int i = 0;i < m; i++){
    int a,b;
    ll w;
    cin >> a >> b >> w;
    g[a].push_back({w, b});
    g2[b].push_back(a);
  }

  // check elements that reach n
  dfs(n);

  // spfa
  queue<int> q;
  vector<ll> d(n + 1, -inf), cnt(n + 1, 0);
  vector<bool> inqueue(n + 1);

  d[1] = 0;
  inqueue[1] = 1;
  q.push(1);

  bool ok = 1;
  while (!q.empty()){
    int u = q.front();
    q.pop();
    inqueue[u] = false;
    for (auto v: g[u]){
      if (!possible.count(v.second)) continue;
      ll x = d[u] + v.first;
      // maximize distance
      if (x > d[v.second]){
        d[v.second] = x;

        if (!inqueue[v.second]){
          q.push(v.second);
          cnt[v.second]++;
          inqueue[v.second] = true;
          if (cnt[v.second] > n + 1){
            // found positive cycle
            ok = 0;
            while (!q.empty()) q.pop();
            break;
          }
        }
      }
    }
  }

  if (ok){
    cout << d[n] << '\n';
  }
  else{
    cout << -1 << '\n';
  }

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
