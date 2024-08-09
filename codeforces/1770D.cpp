// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const string yes = "YES", no = "NO";

const int N = 1e5;

void solve(){
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i =0 ;i< n; i++) cin >> a[i], a[i]--;
  for (int i =0 ;i< n; i++) cin >> b[i], b[i]--;

  vector<int> g[n];  
  for (int i = 0; i < n; i++){
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  vector<bool> vis(n); 

  // count |V| = |E|
  int v, e, loop;
  function<void(int)> dfs = [&](int u){
    if (vis[u]) return; 
    vis[u] = 1 ;
    v++;
    for (auto v: g[u]){
      e++;
      dfs(v);
      if (u == v) loop++;
    }
  };

  ll ans = 1;
  for (int i =0 ;i < n; i++){
    if (vis[i]) continue;
    v = e = loop = 0;
    dfs(i);
    if (v * 2 != e){
      ans = 0;
    }
    else if (loop){
      ans *= n;
    }
    else ans *= 2;
    ans %= mod;
  }

  cout << ans << endl;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
