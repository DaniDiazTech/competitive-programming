// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
void solve(){
  int n; cin >> n;
  vector<double> a(n + 1);
  vector<ll> v(n + 1);
  ll d = 1e10;
  for (int i =1;i <= n; i++){
    ll x;
    float px; cin >> x >> px;
    ll pxx = d * px;
    v[i] = x * pxx;
  }
  sort(v.begin(), v.end());
  double ans = 0;
  for (int i = 1;i <= n; i++){
    a[i] = a[i - 1] + ((1.0 * v[i]) / (1.0 * d));
    ans += a[i];
  }
  ans /= 1.0 * n;
  cout << setprecision(7);
  cout << ans << '\n';
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
