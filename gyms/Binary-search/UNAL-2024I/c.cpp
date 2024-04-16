// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, c;
  cin >> n >> c;
  ll s = 0, ss = 0;
  for (int i =0 ;i < n; i++){
    ll x; cin >> x;
    s += x;
    ss += x * x;
  }


  ll l = 1, r = sqrt((10e18) / (double)((2 * n)));
  while (l + 1 < r){
    ll m = l + (r - l) / 2;
    ll x = ss + 4 * m * s + 4 * n * m * m;
    if (x <= c){
      l = m;
    }
    else r = m;
  }
  cout << l << endl;
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
