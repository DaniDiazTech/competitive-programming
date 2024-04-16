// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0;i < n; i++){
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  
  int q; cin >> q;
  while (q--){
    ll l ,u; cin >> l >> u; 

    ll low = l, high = n;
    while (low + 1 < high){
      ll m = low + (high - low) / 2;
      if (a[m] - a[l - 1] <= u) low = m;
      else high = m;
    }
    // series
    ll k = a[low] - a[l - 1];
    ll p = a[high] - a[l - 1];
    if ( (k * u) - ((k)* (k - 1) / 2) >= (p * u) - ((p) * (p - 1) / 2)){
      cout << low;
    }
    else cout << high;
    cout << ' ';
  }
  cout << '\n';
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
