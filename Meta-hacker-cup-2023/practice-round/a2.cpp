// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll a, b, c;
  cin >> a >> b >> c;
  ll l = 0, r =1e17;
  while (l + 1 < r){
    ll m = l + ((r - l) >> 1);
    ll cost = 0;


    ll buns= m + 1;
    ll patties = m; 

    // need m patties and cheese
    if (2ll * a <= b){
      // Only choose A
      cost += a * m;

      buns -= 2 * a;
      patties -= m;
    }
    else if (a > b){
      // Only choose B
      ll lim = ((m + 2) / 2);
      cost +=  lim * b;
      buns -= 2 * ();
    }
    else{
      // Chose a combination of both
      cost += (m / 2ll) * b + (m % 2ll) * a;
    }

    if (cost <= c) l = m;
    else r = m;
  }
  cout << l << '\n';
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
    cout << "Case #" << t << ": ";
    solve();
  }
}
