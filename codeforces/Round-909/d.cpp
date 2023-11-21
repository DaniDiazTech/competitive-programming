// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  map<ll,ll> mp;
  for (int i = 0;i < n; i++){
    ll x; cin >> x;
    mp[x]++;
  }
  ll ans = mp[1] * mp[2];
  for (auto p: mp){
    ans += (p.second * (p.second - 1)) / 2;
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
