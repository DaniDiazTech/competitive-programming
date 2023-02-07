// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int binpow(int a, int b, int m = MOD){
  a %= m;
  int res = 1;
  while(b > 0){
    if (b & 1)
      res = res * a % m;
    
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

// int arr[MAX];
void solve(){
  int n;
  cin >> n;

  int number = 1, divisors = 1, sum = 1, product = 1, ftl_divisors = 1;

  while (n--){
    int x, k; cin >> x >> k;
    number = (number * ( binpow( (x % MOD), (k % MOD) ))) % MOD;

    divisors  = divisors* (k + 1) % MOD;
    sum = (sum * ( ( (binpow(x, k + 1) - 1) * binpow(x - 1, MOD - 2)) % MOD) % MOD);

    product = binpow(product, k + 1) * binpow(binpow(x, (k * (k + 1) / 2)), ftl_divisors ) % MOD;
    ftl_divisors = ftl_divisors * (k + 1) % (MOD - 1);
  }

  cout << divisors << " " << sum << " " << product << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
