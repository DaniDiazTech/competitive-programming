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

const int MAX = 1e6 + 1;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

vector<int> g[MAX];
bool visited[MAX];

void dfs(int s){
  if (visited[s]) return;
  visited[s] = true;
  for (auto u: g[s]){
    dfs(u);
  }
}

// int arr[MAX];
void solve(){
  int n, m;
  cin >> n >> m;
  string a[n + 2];
  a[0] = a[n + 1] = string(m+2, ':');
  for (int i = 1; i <= n; i++){
    string s = ":";
    string x; cin >> x;
    s += x + ':';
    a[i] = s;
  }

  for (int i = 1; i <= n;i++){
    int ind = m * (i - 1); 
    for (int j = 1; j <= m; j++, ind++){
      if (a[i][j] == '.'){
        if (a[i][j + 1] == '.'){
          int adj = ind + 1;
          g[ind].pb(adj);
          g[adj].pb(ind);
        }
        if (a[i + 1][j] == '.'){
          int adj = ind + m;
          g[ind].pb(adj);
          g[adj].pb(ind);
        }
        g[ind].pb(ind);
      }
    }
  }

  int ans = 0;
  for (int i =0; i < MAX; i++){
    if (g[i].size() && !visited[i]){
      ans++;
      dfs(i);
    }
  }
  cout << ans  << endl;
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
