// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, q;
  cin >> n >> q;

  string s; cin >> s;

  vector<vector<int>> a(26);
  for (int i = 0; i < n; i++){
    int j = s[i] - 'a';
    a[j].push_back(i);
  }
  
  // for (int i = 0; i < 26; ++i){
  //   cout << "i: " << i << " -> ";
  //   for (auto x: a[i]) cout << x << ' ';
  //   cout << endl;
  // }

  while (q--){
    int l, r; cin >> l >> r;
    l--; r--;
    // cout << "L, R: " << l << " " << r << endl;
    int mx = 0;
    for (int i = 0; i < 26 ; i++){
      for (int j = 0; j < 26; j++){
        if (i == j) continue;
        if (!(a[i].size() && a[j].size())) continue;
        // cout << i << " " << j << '\n';
        int o = lower_bound(a[i].begin(), a[i].end(), l) - a[i].begin();
        int p = lower_bound(a[j].begin(), a[j].end(), r) - a[j].begin();
        int ft = a[i][o], sec  = a[j][p];
        // cout << "RANGE: " << ft << " " << sec << endl;
        if (!(ft >= l && sec <= r)) continue;
        if (sec > ft ){
          // cout << "HEREEEE\n";
          // cout << mx << endl;
          mx = max(mx, sec - ft + 1);
          // cout << mx << endl;
        }
      }
    }
    ll sum = (mx * (mx + 1) / 2) - 1;    
    cout << max(sum, 0ll) << '\n';
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
    solve();
  }
}
