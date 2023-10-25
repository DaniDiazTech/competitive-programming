// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e5 + 100;
vector<ll> primes;
vector<bool> sieve(N, 0 );

ll binpow(ll a, int b){
  if ( b == 0 ) return 1;
  if ( b == 1 ) return a;

  ll half = binpow(a, b / 2);
  return half  * half * (b & 1 ? a : 1);
}

ll phi(ll n){
  // prime: freq
  ll res = 1;
  ll l = n;
  for ( auto p : primes ){
    if (p * p > n){
      break;
    }
    int cnt = 0;
    while (n % p == 0 ){
      n /=p;
      cnt++;
    }
    if (cnt)
      res *= binpow(p, cnt) - binpow(p, cnt - 1);
  }
  if (n > 1){
    res *= (n - 1);
  }

  return res;
}

void solve(){
  ll a, b;
  cin >> a >> b;
  ll g = __gcd(a, b);
  // Inclusion exclusion
  ll ans = 0 ;
  // decompose b
  ll l = b;

  l /= g;
  vector<ll> v;

  for (auto p: primes){
    if (p * p > l) break;
    if (l % p ==0 ){
      v.push_back(p);
      while ( l % p == 0 ) l/=p;
    }
  }

  if (l > 1) v.push_back(l);
  int sz = v.size();
  ll x = (a + b - 1);

  for (int mask= 0 ; mask < (1 << sz); mask++){
    ll prod = 1; 
    // cout << "MASK: " << mask << endl;
    for (int i = 0; i < sz; i++){
      if (mask & (1 << i)){
        prod *= v[i];
      }
    }
    ll count = (x / (g * prod)) - ((a - 1) / (g * prod));
    if (__builtin_popcount(mask) % 2 == 0){
      ans += count;
    }
    else{
      ans -= count;
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

  // sieve
  for (int i = 2; i < N ; i++){
    if (sieve[i] == 1) continue;
    primes.push_back(i);
    for (int j = i; j < N; j+=i){
      sieve[j] = 1;
    }
  }
  

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
