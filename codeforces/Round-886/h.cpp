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

vector<pair<int, int>> g[MAX];
int vis[MAX], dis[MAX];

void dfs(int u){
  vis[u] = 1;
  for (auto x: g[u]){
    if (!vis[x.ff]){
      dis[x.ff] = dis[u] + x.ss; 
      dfs(x.ff);
    }
  }
}

void solve(){
  int n, m;
  cin >> n >> m;
  forn(i,n + 1){
    g[i].clear();
    dis[i] = 0;
    vis[i] = 0;
  }

  vector<vii> v;
  forn(i,m){
    int a,b, c;
    cin >> a >> b >> c;
    v.pb({a,b,c});
    g[a].pb({b,c});
    g[b].pb({a,-c});
  }
  for (int i = 1; i <= n;i++){
    if (!vis[i]){
      dfs(i);
    }
  }
  for (auto x: v){
    if (dis[x[1]] - dis[x[0]] != x[2]){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
