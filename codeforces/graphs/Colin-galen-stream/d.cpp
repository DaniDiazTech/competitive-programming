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


vii g[MAX];
int vis[MAX];
vii k,l;
bool bip = 1;
void dfs(int u, int c){
  vis[u] = c;
  if (c == 0) k.pb(u);
  else l.pb(u);
  for (auto x: g[u]){
    if (vis[x] == -1){
      dfs(x, !c);
    }
    else if (vis[x] == c){
      bip = 0;
      return;
    }
  }
}
void solve(){
  int n, m;
  cin >> n >> m;
  memset(vis, -1, sizeof vis);
  forn(i,m){
    int a, b; cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  for (int i = 1; i<=n && bip; i++){
    if (vis[i] != -1) continue;
    dfs(i, 0);
  }
  if (!bip){
    cout << -1 << endl;
  }
  else{
    cout << sz(k) << endl << k;
    cout << sz(l) << endl << l;
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
