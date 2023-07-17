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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

vector<int> g[MAX];
int vis[MAX];

void solve(){
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    g[a].pb(b);
  }

  // BFS with dp
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (auto x: g[v]){
      // if (vis[v] == 0)
      q.push(v);
      vis[x] = (vis[x] + vis[v]) % mod;
      cout << "VIS: " << x << " CURRENT:  " << vis[x] << endl;
    }
  }
  cout << vis[n] << endl;
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
