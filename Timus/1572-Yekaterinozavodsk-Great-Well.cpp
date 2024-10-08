// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


void solve(){
  // 0 circle, 1 square, 2 triangle
  vector<double> mn = {2, 1, sqrt(3.0) / 2.0}, mx = {2, sqrt(2), 1};
  int t, L;
  cin >> t >> L;
  t--;

  int q;
  cin >> q;
  int cnt = 0;
  while (q--){
    int type, x;
    cin >> type >> x;
    type--;

    if (mx[t] * (1.0 * L) >= mn[type] * x) cnt++;
  }
  cout << cnt << '\n';
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
