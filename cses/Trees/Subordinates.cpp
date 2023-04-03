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

vector<int> G[MAX];
int vis[MAX];

int dfs(int u, int p){
  int cnt = 0;
  for (auto g: G[u]){
    if (g != p){
      cnt++;
      cnt += dfs(g, u);
    }
  }
  return vis[u] = cnt;
}

void solve(){
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++){
    int x; cin >> x;
    G[i].pb(x);
    G[x].pb(i);
  }
  dfs(1, 0);
  FOR(i, 1, n+1){
    cout << vis[i] << " ";
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
