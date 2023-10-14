// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 3 * 1e5;
vector<int> g[N];
int vis[N], par[N];

set<int> cycle;

void dfs(int u){
  vis[u] = 1;
  for (auto x: g[u]){
    if (vis[x] == 2 || par[u] == x) continue; 
    if (vis[x] == 1){
      // found cycle
      for (int l = u; l !=x; l = par[l]){
        cycle.insert(l); 
      }
      cycle.insert(x);
      // cout << "CYCLE: ";
      // for (auto r: cycle){
      //   cout << r << " ";
      // }
      // cout << endl;
    }
    else{
      par[x] = u;
      dfs(x);
    }
  }
  vis[u] = 2;
}

ll dfs2(int u, int par){
  ll to = 0;
  int cnt  = 0;
  for (auto x: g[u]){
    if (!cycle.count(x) && x != par){
      to += dfs2(x, u); 
      cnt++;
    }
  }
  return to + 1;
}

void solve(){
  int n;
  cin >> n;
  cycle.clear();

  for (int i =0 ;i  <= n + 1 ; i++){
    g[i].clear();
    vis[i]= 0;
    par[i]= -1;
  }

  for (int i =0 ;i < n; i++){
    int a, b; cin >>a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1);
  ll ans = 0;
  for (auto x: cycle){
    ll sz = dfs2(x, -1);
    // cout << "X: " << x << " SZ : " << sz << endl;
    ans += ((sz - 1ll) * (sz) / 2ll) + (sz * (n - sz));
  }
  cout << ans << '\n';

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
