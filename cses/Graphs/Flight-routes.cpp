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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

vector<pii> g[MAX];
int dis[MAX];
void solve(){
  int n, m, k; cin >> n >> m >> k;
  vii ans;
  forn(i,m){
    int a, b, c; cin >>a >> b >> c; 
    g[a].pb({c, b});
  }

  for (int i =0 ; i<=n; i++) dis[i] = oo;

  // Dijkstra
  priority_queue<pii> pq;
  pq.push({0, 1});
  dis[1] = 0;

  while (!pq.empty()){
    pii p = pq.top(); pq.pop();
    int w = p.ff, u = p.ss;
    for (auto x: g[u]){
      // cout << x.ss << " " << x.ff << endl;
      if (dis[x.ss] > dis[u] + x.ff){
        // Better answer found, relax
        pq.push({-x.ff, x.ss});
        dis[x.ss] = dis[u] + x.ff;
      }
      if (x.ss == n){
        // cout << "HERE" << endl;
        ans.pb(dis[x.ss]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < k; i++){
    cout << ans[i] << " ";
  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
