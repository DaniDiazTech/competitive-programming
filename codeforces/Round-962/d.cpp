// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, x;
  cin >> n >> x;

  ll ans = 0;
  for (ll a = 1; a <= x -2 ; a++){
    ll b = 1;
    while ((n - (a * b)) / (a + b) > 0 && (x - a - b) > 0){
      // add c
      ans +=  min(x - a - b, (n - (a * b)) / (a + b));

      b++;
    }
  }
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
