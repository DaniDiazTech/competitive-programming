// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 3000;
const ll inf = 1e15;

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



// {distance, node}
vector<pair<ll,int>> g[N];

/*
SFPA Shortest path faster algorithm (SPFA)
Calculates single source shortest (simple) path with negative cycles.
Complexity:
Worst: O(nm)
Average: O(m)
*/

bool spfa(int s, int n, vector<ll>& d) {
    d.assign(n + 1, -inf);
    vector<int> cnt(n + 1, 0);
    vector<bool> inqueue(n + 1, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for (auto v : g[u]) {
            int w = v.first;
            int to = v.second;
            if (!possible.count(to)) continue;

            if (d[u] + w > d[to]) {
                d[to] = d[u] + w;

                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
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
  vector<ll> d;
  bool ok = spfa(1, n, d);

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
