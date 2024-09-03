// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n;
  cin >> n;
  
  ll trueans = 1;
  ll K = 100;

  ll s = max(1ll, (ll)(n - K));

  for (ll i = s; i <= n; i++){
    for (ll j = s; j <= n; j++){
      for (ll k = s; k <= n; k++){
        trueans = max(trueans, lcm(lcm(i, j), k));
      }
    }
  }


  cout << trueans << endl;
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
