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

const int MAX = 4000;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

vector<vii> edges;
int vis[MAX], dis[MAX], par[MAX];


void solve(){
  int n, m;
  cin >> n >> m;
  for (int i =0;i < m; i++){
    vii v(3);
    cin >> v[0] >> v[1] >> v[2];
    edges.pb(v);
  }
  int x = -1;
  for (int i =1; i <= n; i++){
    x = -1;
    for (auto e: edges){
      if (dis[e[1]] > dis[e[0]] + e[2]){
        dis[e[1]] = dis[e[0]] + e[2];
        par[e[1]] = e[0];
        x = e[0];
      }
    }
  }
  // X has the result of the nth iteration
  if (x == -1){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;

  // Now traceback n times to get a node that it's guaranteed to b in the cycle
  for (int i = 0; i < n; i++){
    x = par[x];
  }

  // Start the path reconstruction
  vii path;
  for (int v = x; ; v = par[v]){
    path.pb(v);
    if (v == x && path.size() > 1)
      break;
  }

  reverse(path.begin(), path.end());
  for (auto x: path) cout << x << " ";
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
