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
typedef vector<int> vii;

const int MAX = 10100;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

vii g[MAX];
int vis[MAX];
void dfs(int u){
  vis[u] = 1;
  for (auto x: g[u]){
    if (!vis[x]){
      dfs(x);
    }
    if (vis[x] == 1){
      // Found
      cout << "Yes";
      exit(0);
    }
  }
  vis[u] = 2;
}
void solve(){
  int n,m;
  cin >> n >> m;
  forn(i,m){
    int a, b; cin >> a >> b;
    g[a].pb(b);
  }
  forn(i,n){
    if (!vis[i])
      dfs(i);
  }
  cout << "No";
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
