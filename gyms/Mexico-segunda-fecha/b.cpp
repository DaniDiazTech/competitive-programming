// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll binpow(ll a, ll b){
  if (b == 0 ) return 1;
  if (b == 1 ) return a;

  ll x = binpow(a, b / 2);
  return ( ( (x * x) % mod) * (b & 1 ? a : 1) ) % mod;
}

const int N = 1e6 + 10;
ll perm[N], invperm[N];

void solve(){
  ll n, q;
  cin >> n >> q;

  ll a[n];
  map<ll, ll> mp;

  for (int i =0 ;i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }

  ll mult = 1;

  for (auto x: mp){
    mult = (perm[x.second] * mult) % mod;
  }

  cout << (mult * invperm[n]) % mod << '\n';

  while (q--){
    ll j, x; 
    cin >> j >> x;
    j--;
    if (a[j] != x){
      // replace
      // Divide by freq[a[j]]    
      mult = (mult * binpow(mp[a[j]], mod - 2)) % mod;
      // Replace
      mp[a[j]]--;
      a[j] = x;
      mp[a[j]]++;

      mult = (mult * mp[a[j]]) % mod;
    }

    cout << (mult * invperm[n]) % mod << '\n';
  }  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  perm[0] = invperm[0] = 1;
  for (ll i = 1;i < N; i++){
    perm[i] = (i * perm[i - 1]) % mod;
    // Inverse
    invperm[i] = binpow(perm[i], mod - 2);
  }

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
