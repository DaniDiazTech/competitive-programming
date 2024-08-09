// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n;
  cin >> n;
  ll a[n];

  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  ll ans = 0;
  for (int sim = 0; sim < 2; sim++){
    vector<ll> b(n);
    map<int, ll> mp;
    ll mx = 0;
    for (int i =0 ;i < n; i++){
      ans += a[i];
      mp[a[i]]++;
      mx = max(mx, mp[a[i]]>=2 ? a[i] : 0ll);
      b[i] = mx;
    }
    for (int i =0 ;i  < n; i++) a[i] = b[i];
  }

  for (int i = 1;i < n; i++){
    ans += a[i] * (n - i);
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
