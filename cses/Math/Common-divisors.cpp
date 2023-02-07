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

int a[MAX + 1];
void solve(){
  int n;
  cin >> n;
  while(n--){
    int x; cin >> x;
    a[x]++;
  };
  // make jumps, like in the sieve of eratosthenes
  // We start with the maximum possible gcd
  // O(max(x_i) * log(max(x_i)))
  for (int gcd = MAX; gcd > 0; gcd--){
    int cnt = 0;
    for (int i = gcd; i <= MAX; i += gcd){
      cnt += a[i];
      if (cnt > 1){
        cout << gcd << endl;
        return;
      }
    }
  }
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
