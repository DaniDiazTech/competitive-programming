// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


void solve(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i =0 ;i < n; i++) cin >> a[i];
  if (n == 1){
    cout << k - 1 + (a[0] < k) << endl;
    return;
  }

  ll g = 0;
  for (int i =0 ;i < n; i++){
    g = gcd(g, a[i]);
  }

  // can create
  // 0, g, 2g, 3g, 4g, .....
  ll x = k - 1;
  // how many 0,g, 2g, 3g, ..., (n - 1)g
  for (int i = 0;i < n; i++){
    if (i * g <= x){
      x++;
    }
    else break;
  }
  cout << x << endl;
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
