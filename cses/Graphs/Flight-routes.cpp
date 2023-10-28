// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6;
vector< pair <int, int> > g[N];
int vis[N];
multiset<int> ans[N];

int n, m, k;

multiset<int> go( int u ){
  if (u == 1){
    multiset<int> s;
    s.insert(0);
    return ans[u] = s;
  }

  vis[u] = 1;
  multiset<int> pq = ans[u];

  for ( auto x: g[u] ){
    if ( vis[x.first] == 1) continue;
    auto p = go(x.first);
  
    for ( auto l: p ){
      int w = l + x.second;
      cout << "U: " << u << " V: " << x.first << " W: " << w << endl;
      if (pq.size() < k){
        pq.insert(w);
      }
      else{
        cout << "W: " << w << " rbegin() : " << *(pq.rbegin()) << endl;
        if (*(pq.rbegin()) > w){
          auto it = pq.end();
          it--;
          pq.erase(it);
          pq.insert(w);
        }
        else{
          break;
        }
      }
    }
  }
  vis[u] = 2;

  return ans[u] = pq;
}

void solve(){
  cin >> n >> m >> k;

  for (int i = 0 ;i < m; i++){
    // invert edges
    int a, b, c; cin >> a >> b >> c;
    g[b].push_back({a, c});
  }
  auto q =   go(n) ;
  for (auto x : q) cout << x  << " ";
  cout << '\n';
  for (int i = 1; i <= n; i++){
    for (auto x: ans[i]) cout << x << " ";
    cout << endl;
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
