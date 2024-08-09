// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 2e5 + 10;

ll f[N], inv[N];

ll binpow(ll a, ll b){
  if (b == 0) return 1;
  if (b == 1) return a;
  ll x= binpow(a, b / 2);
  return (((x * x) % mod) * ( b & 1 ? a : 1ll) ) % mod;
}

ll bin(ll n, ll k){
  if (k > n) return 0;
  return (((f[n] * inv[k]) % mod) * (inv[n - k])) % mod;
}

void solve(){

  int n, k; cin >> n >> k;

  int o = 0, z = 0;
  for (int i = 0;i < n; i++){
    char ch;
    cin >> ch;
    o += ch == '1';
    z += ch == '0';
  }

  ll ans = 0;

  for (int i = (k + 1) / 2; i <= k; i++){
    ans = (ans  + (bin(o, i) * bin(z, k - i)) % mod) % mod;
  }

  cout << ans << endl;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  f[0] = inv[0] = 1;

  for (ll i = 1; i < N; i++){
    f[i] = (f[i - 1] * i) % mod;
    inv[i] = binpow(f[i], mod - 2);
  }


  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
