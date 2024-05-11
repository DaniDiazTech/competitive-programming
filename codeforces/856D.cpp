// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const string yes = "YES", no = "NO";

/*
Create primes up to a number N.
Complexity: O(n ln ln n)
*/

void gen_primes(vector<bool> &sieve, set<int> &primes, int n){
  sieve.assign(n + 1, 1);
  primes.clear();
  sieve[0] = sieve[1] = 0;

  for (long long i = 2; i <= n; i++){
    if (sieve[i]){
      primes.insert((int)i);
      for (long long j = i * i; j <= n; j+=i){
        sieve[j] = false;
      }
    }
  }

}
int m = 0;
vector<ll> aprime;
const int N = 5000;
vector<ll> fact(N), inv(N);
vector<vector<ll>> dp(N, vector<ll>(N, -1));

ll binpow(ll a, ll b){
  if (b == 0) return 1;
  if (b == 1) return a;
  ll x = binpow(a, b / 2);
  return (((x * x) % mod) * (b & 1 ? a : 1)) % mod ;
}

ll go(int x, int y){
  if (x == m) return y == 0;
  if (y < 0) return 0;
  if (dp[x][y] != -1) return dp[x][y];
  return dp[x][y] = ((inv[aprime[x] - 1] * go(x + 1, y - 1)) % mod + (inv[aprime[x]] * go(x + 1, y)) % mod) % mod; 
}

void solve(){
  int n;
  cin >> n;
  vector<bool> s;
  set<int> primes;
  gen_primes(s, primes, 1000006);
  fact[0] = inv[0] = 1;

  for (ll i = 1; i < N; i++){
    fact[i] = (i * fact[i - 1]) % mod;
    inv[i] = binpow(fact[i], mod - 2);
  }

  map<int,int> p, np;
  int cnt = 0;
  for (int i = 0;i  < 2 *  n ; i++){
    int x; cin >> x;
    if (primes.count(x)){
      p[x]++;
      cnt++;
    }
    else{
      np[x]++;
    }
  }

  if (cnt < n){
    cout << 0 << endl;
    return;
  }

  ll ans = fact[n];

  for (auto nonprime: np){
    ans *= inv[nonprime.second];
    ans %= mod;
  }

  m= p.size();

  for (auto prime: p){
    aprime.push_back(prime.second);
  }


  ans *= go(0, n);
  ans %= mod;

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
