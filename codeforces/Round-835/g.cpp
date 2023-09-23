// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
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

const int MAX = 1e5 + 100;
const int MIN = -MAX;
const string yes = "YES", no = "NO";


int n, a, b;
vector<pii> g[MAX];
set<int> s;
// Doing dfs from a
void dfs1(int u, int par, int x){
  if (u != b) s.insert(x);
  for (auto &p: g[u]){
    int v = p.ff, w = p.ss;
    if (v == b || v == par) continue;
    dfs1(v, u, x ^ w);
  }
  return;
}

// DFS from b
bool dfs2(int u, int par, int x){
  if (u != b && s.count(x)){
    return true;
  }
  for (auto &p: g[u]){
    int v = p.ff, w = p.ss;
    if (v == b || v == par) continue;
    if(dfs2(v,u, x^w)) return true;
  }
  return false;
}

void solve(){
  cin >> n >> a >> b;
  s.clear();
  forn(i,n + 2) g[i].clear();
  forn(i,n - 1){
    int u,v,w; cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u,w});
  }
  
  // Calculate reachable by A
  dfs1(a,-1,0); // stored in s
  if(dfs2(b,-1, 0)) cout << "YES";
  else cout << "NO";
  cout << endl;
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
