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

int vis[MAX], parent[MAX],  vis2[MAX],  vis3[MAX];
bool cycle[MAX];
vii g[MAX];

void dfs(int u, int par){
  vis[u] = 1;
  parent[u] = par;

  for (auto x: g[u]){
    if (vis[x] == 2 || x == par) continue;
    if (vis[x] == 1){
      // cycle
      cycle[x] = 1;
      for (int cur= u; cur != x; cur = parent[cur]){
        cycle[cur] = 1;
      }
    }
    else if (!vis[x]){
      dfs(x, u);
    }
  }
  vis[u] = 2;
}

void solve(){
  int n, A, B;
  cin >> n >> A >> B;
  forn(i, n + 3){
    g[i].clear();
    vis3[i]= vis[i] = vis2[i] = parent[i] =   cycle[i] = 0;
  }

  for (int i = 1; i <= n; i++){
    int a, b; cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  g[0].pb(1);
  // One dfs
  // Detect cycles in a graph
  dfs(0, -1);
  
  
  queue<int> q;q.push(A);  
  // vis2 stores distance
  vis2[A] =0;
  while (q.size()){
    int u = q.front(); q.pop();
    
    for (auto x: g[u]){
      if (!vis2[x] && x != A){
        vis2[x] = vis2[u] + 1;
        q.push(x);
      }
    }
  }

  q.push(B);
  vis3[B] = 0;
  bool f = 1;
  while (q.size()){
    int u = q.front();q.pop();
    
    if (cycle[u]){
      // First entry found
      if (vis2[u] <= vis3[u]){
        f = 0;
      }
      break;
    }
    
    for (auto x: g[u]){
      if (!vis3[x] && x != B){
        vis3[x] = vis3[u] + 1;
        q.push(x);
      }
    }
  }
  cout << (f ? yes: no) << endl;
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
