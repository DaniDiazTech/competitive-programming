// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

double pi = 3.1415926535;

void solve(){
  double v, a, k;
  cin >> v >> a >> k;

  a = a * pi / 180.0;
  double cosa = cos(a), sina = sin(a);
  double eps = 1e-9;
  v = v * v;
  double ans = 0;
  while (v > eps){
    ans += v * cosa * sina / 5.0;
    v /= k;
  }
  cout << setprecision(2) << fixed;
  cout << ans << '\n';
}

void solve2(){
  double v, a, k;
  cin >> v >> a >> k;
  a = a * pi / 180.0;
  double cosa = cos(a), sina = sin(a);
  double ans = (v * v * cosa * sina / 5.0) * (k / (k - 1));
  cout << setprecision(2) << fixed;
  cout << ans << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  solve2();
}
