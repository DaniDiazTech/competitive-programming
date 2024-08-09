// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;

  ll n = s.size();
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++){
    p[i] += (s[i - 1] == '0' ? -1 : 1);
    p[i] += p[i - 1];
  }

  ll ans= 0;
  // stores time pi has appeared
  map<int, ll> mp;
  for (ll i = 0;i <= n; i++){
    ans += ( (n - i + 1) * mp[p[i]] );
    ans %= mod;

    mp[p[i]] += i + 1;
    mp[p[i]] %= mod;
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
