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

bool is_prime(int n){
  if (n % 2 == 0 ) return false;
  for (int i = 3; i * i <= n; i+=2)
    if (n % i == 0) return false;
  return true;
}

// int arr[MAX];
void solve(){
  int n = 2e6;
  // int ans = 2;
  // for (int i = 3; i < n; i+=2)
  //   ans += is_prime(i) ? i : 0;

  // sieve
  vector<bool> sieve(n + 1, false);
  int ans = 0;
  sieve[0]= sieve[1] = true;
  for (int i = 2; i * i < n; i++){
    if (!sieve[i]){
      for (int j = i * i; j < n; j+=i){
        sieve[j] = true;
      }
    }
  }
  // cout << ans << endl;
  for (int i = 0; i < n; i++)
    if (!sieve[i]) ans += i;
  cout << ans << endl;
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
