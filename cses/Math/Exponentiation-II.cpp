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

int binary_exponentiation(int base, int exponent, int mod){
  // Base case
  if (exponent == 0) return 1;
  
  // Calculate a ^ (b / 2)
  int result = binary_exponentiation(base, exponent / 2, mod); 

  // If exponent is odd
  if (exponent & 1){
    // a^(b/2) * a^(b/2) = a ^(b)
    // But if the exponent is odd, then we must
    // Multiply by the base again
    // a^(b/2) * a^(b/2) * a = a ^(b)
    result = (((result * result) % mod) * base) % mod;
  }
  else{
    // a^(b/2) * a^(b/2) = a ^(b)
    result = (result * result) % mod;
  }
  return result;
}

// int arr[MAX];
void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  cout << binary_exponentiation(a, binary_exponentiation(b, c, MOD - 1), MOD) << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
