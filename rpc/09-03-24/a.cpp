// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  double s = 0, l = 0;
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    s += a[i];
  }
  sort(a.rbegin(), a.rend());
  for (int i =0 ;i < min(n, m + k); i++){
    l += a[i];
  }
  
  cout << setprecision(10);
  cout << ((l / s) * 100) << '\n';
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
