// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  ll ans = 0;
  int a[n][n], b[n][n];
  for (int i =0 ; i < n; i++){
    for (int j = 0; j < n; j++){
      char ch; cin >> ch;
      a[i][j] = ch - 'a';
      b[i][j] = 0;
    }
  }

  for (int i =0 ; i < n; i++){
    for (int j = 0; j < n; j++){
      int x  = abs(a[i][j] - a[n - j - 1][i]);
      ans += x;
      a[i][j] = a[n - j - 1][i] = max(a[i][j], a[n - j - 1][i]);
      // if (x > 0 ){
      //   cout << i << ", " << j << " CNT: " << x << endl;
      // }
    }
  }
  for (int i =0 ; i < n; i++){
    for (int j = 0; j < n; j++){
      int x  = abs(a[i][j] - a[n - j - 1][i]);
      ans += x;
      a[i][j] = a[n - j - 1][i] = max(a[i][j], a[n - j - 1][i]);
      if (x > 0 ){
        // cout << i << ", " << j << " CNT: " << x << endl;
      }
    }
  }
  // for (int i =0 ; i < n; i++){
  //   for (int j = 0; j < n; j++){
  //     cout << a[i][j] << " ";
  //   }
  //   cout << endl;
  // }
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
