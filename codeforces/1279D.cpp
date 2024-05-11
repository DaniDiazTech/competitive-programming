// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const string yes = "YES", no = "NO";

ll binpow(ll a, ll b, ll m){
  ll ans = 1;
  a %= m;
  while (b){
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return ans;
}

ll inv(ll a){
  return binpow(a, mod - 2, mod);
}


void solve(){
  ll n;
  cin >> n;
  map<ll, ll> freq;
  vector<vector<ll>> a(n);
  for (int i =0;i < n; i++){
    int k; cin >> k;
    for (int j =0; j < k; j++){
      ll x; cin >> x;
      freq[x]++;
      a[i].push_back(x);
    }
  }
  ll ans = 0;

  for (int i = 0;i < n; i++){
    for (auto x: a[i]){
      ll cont = (( freq[x] * inv(n *n)) % mod) * (inv(a[i].size()));
      cont %= mod;
      ans += cont;
      ans %= mod;
    }
  }
  cout << ans << '\n';
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
