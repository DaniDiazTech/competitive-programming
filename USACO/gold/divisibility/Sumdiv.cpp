// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll  long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll binpow(ll a, ll b){
  a %= mod;
  if (b == 0) return 1;
  if (b == 1) return a;
  ll x = binpow(a, b / 2);
  return ((x * x) % mod * (b & 1 ? a : 1)) % mod;
}

ll applymod(ll n){
  return ((n % mod) + mod) % mod;
}

const int N = 1000100;
bool sieve[N];
vector<ll> primes;

void solve(){
  for (int i = 2; i< N; i++){
    if (!sieve[i]){
      primes.push_back(i);
      for (int j = i * 2; j < N; j+=i){
        sieve[j] = 1;
      }
    }
  }
  ll a, b; cin >> a >> b;

  ll ga = 1;
  for (auto p: primes){
    if (p * p > a) break;
    if (a % p == 0){
      ll k = 0;
      while (a % p == 0){
        k++;
        a /= p;
      }
      ga *= applymod( binpow(p, (  ( ((b % (mod - 1)) * k) % (mod - 1)) + 1 ) % (mod - 1))  - 1 );
      ga %= mod;

      // inverse of p - 1
      ga *= applymod( binpow(applymod(p - 1), mod - 2) );
      ga %= mod;
    }
  }

  if (a > 1){
    ll p = a;
    if ((p - 1) % mod == 0){
      ga *= (b +1) % mod;
    }
    else{
      ga *= applymod( binpow(p, ((b % (mod -1)) + 1) % (mod - 1))  - 1 );
      ga %= mod;
      // inverse of p - 1
      ga *= applymod( binpow(applymod(p  - 1), mod - 2) );
    }
    ga %= mod;
  }
  cout << ga << '\n';

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #else
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
