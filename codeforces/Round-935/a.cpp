// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll a, b, c; cin >> a >> b >> c;
  ll ans = a;
  ans += b / 3;
  if (b % 3 > 0 && b % 3 + c < 3){
    cout << -1 << endl;
    return;
  }
  ans += ((b % 3) + 2 + c) / 3;
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
