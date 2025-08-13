// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 0;i < n - 1; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (n == 2){
    cout << 0 << endl;
    return;
  }

  int d = 0;

  int root = 0;
  int cur = 0;

  vector<int> mx( n + 1);


  function<void(int, int)> last = [&](int u, int p){
    int x= 0;
    for (auto v: g[u]){
      if (v == p) continue;
      last(v, u); 
      x++;
    }   

    if ( x== 0){
      mx[p]++;
    }
  };

  last(1,0);

  if (g[1].size() == 1){
    mx[g[1][0]]++;
  }


  int ans =0 , mxleaf = 0;

  for (int i = 1; i <= n; i++){
    ans += mx[i];
    mxleaf = max(mxleaf, mx[i]);
  }
  cout << ans - mxleaf << endl;
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
