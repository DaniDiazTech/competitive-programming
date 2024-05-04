// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  double r;
  cin >> n >> r;
  double ans = 2 * (3.1415926535) * r;
  vector<pair<double, double>> v(n);

  for (auto &p: v) cin >> p.first >> p.second;
  
  for (int i = 0;i < n; i++){
    int j = (i - 1 + n) % n;
    double x2 = (v[i].first - v[j].first) * (v[i].first - v[j].first);
    double y2 = (v[i].second - v[j].second) * (v[i].second - v[j].second);
    ans += sqrt(x2 + y2);
  }

  cout << setprecision(2) << fixed;
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
