// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int m = 20000;
  int a[3][m];
  for (int k = 0;k < 3; k++){
    for (int i = 0;i < m; i++){
      a[k][i] = 0;
    }
  }
  
  for (int k = 0 ;k < 3; k++){
    int n; cin >> n;
    for (int i = 0; i< n; i++){
      int x; cin >> x;
      a[k][x] = 1;
    }
  }
  vector<int> g[3];
  for (int k=0; k<3; k++){
    for (int i =0; i< m; i++){
      if (a[k][i] && !a[(k + 1) % 3][i] && !a[(k + 2) % 3][i]){
        g[k].push_back(i);
      }
    }
  }
  int mx =0;
  mx = max( max(mx, (int)g[0].size()), max((int)g[1].size(), (int)g[2].size()));
  for (int k = 0; k < 3; k++){
    if ((int)g[k].size() == mx){
      cout << k + 1 << " " << mx;
      for (auto x: g[k]){
        cout << ' ' << x;
      }
      cout << '\n';
    }
  }
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
    cout << "Case #" << t << ":\n";
    solve();
  }
}
