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

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


vii g[MAX];
int in[MAX], out[MAX], depth[MAX], dis[MAX];
pii mx = {-1, -1};
int cnt = 0;
int ans = -1;
int n, k , c;

void dfs(int u, int p){
  depth[u] = depth[p] + 1;
  in[u] = ++cnt; 
  if (depth[u] > mx.ff){
    mx = {depth[u], u};
  }
  for (auto x: g[u]){
    if (x != p){
      dfs(x, u);
    }
  }
  out[u] = ++cnt;
}

void dfs2(int u, int p){
  if (u == 1){
    dis[u] = mx.ff;
  }
  else{
    dis[u] = dis[p] + (((in[u] <= in[mx.ss]) && out[u] >= out[mx.ss])  ? -1 : 1);
  }
  ans = max(ans, dis[u] * k - (c * depth[u]));
  for (auto x: g[u]){
    if (x != p){
      dfs2(x, u);
    }
  }
}


void solve(){
  cin >> n >> k >> c;
  mx = {-1, -1};
  cnt = 0;
  depth[0] = -1;
  ans = -1;
  for (int i = 1; i <= n; i++){
    g[i].clear();
    dis[i] = depth[i] = in[i] = out[i] = 0;
  }
  forn(i,n - 1){
    int a, b; cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1, 0);
  dfs2(1, 0);
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
