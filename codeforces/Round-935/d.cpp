// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  vector<ll> a(n + 1), b(n + 1), c(n + 1);
  for (int i = n; i >= 1; i--){
    cin >> a[i] ;
  }
  for (int i = n; i >= 1; i--){
    cin >> b[i] ;
  }

  for (int i = 1; i <= n; i++){
    b[i] = min(b[i], a[i]);
    b[i] += b[i - 1];
  }

  // for (int i = 0 ;i <= n; i++){
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0 ;i <= n; i++){
  //   cout << b[i] << " ";
  // }
  // cout << endl;
  for  (int i = 1;i <= n; i++){
    c[i] = a[i] + b[i - 1];
  }

  ll mn = 1e18;
  for (int k = 0; k < m; k++){
    mn = min(mn, c[n - k]);
  }

  cout << mn << '\n';
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
