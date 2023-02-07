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

vector<int> g[MAX];
int visited[MAX];

void dfs(int s){
  if (visited[s]) return;
  visited[s] = true;
  for (auto u: g[s]){
    dfs(u);
  }
}

void solve(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int cnt = -1;
  vector<int> comp;
  for (int i = 1; i <= n; i++){
    if (!visited[i]){
      cnt++;
      comp.pb(i);
      dfs(i);
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < (int)comp.size() - 1; i++){
    cout << comp[i] << " " << comp[i +  1] << endl;
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
