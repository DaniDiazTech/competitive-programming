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

int target = 600851475143;
const int sz = sqrt(target);
// int arr[MAX];
void solve(){
  bool sieve[sz + 10000];
  int mx = MINF;
  for (int i = 2; i * i < target; i++){
    if (!sieve[i]){
      if (target % i == 0)
        mx = i;

      for (int j = i; j * j < target; j += i){
        sieve[j] = 1;
      }
    }
  }
  cout << mx << endl;

  // Improved version
  mx = MINF;
  for (int i = 2; i * i < target; i++){
    if (target % i == 0){
      while (target % i == 0)
        target /= i;
      mx = i;
    }
  } 

  if (target != 1)
    cout << target << endl;
  else
    cout << mx << endl;
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
