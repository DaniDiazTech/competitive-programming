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


const int N = 2 * 1e5;

vector<int>  G[N];
int vis[N];
int cost[N];
// Current node: u
// Check the minimum value of each component
int dfs(int u){
  vis[u] = 1;
  int ans = cost[u];
  for (auto v: G[u]){
    if (vis[v]){
      continue;
    }
    ans = min(ans, dfs(v));
  }
  return ans;
}

// int arr[MAX];
void solve(){
  int n,m;
  cin >> n >> m;
  vector<pii> c;
  forn(i,n){
    cin >> cost[i];
  }

  // Create the graph
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].pb(v);
    G[v].pb(u);
  }

  int answer = 0;

  for (int i = 0; i < n; i++){
    if (!vis[i]){
      answer += dfs(i);
    }
  }

  cout << answer << endl;
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
