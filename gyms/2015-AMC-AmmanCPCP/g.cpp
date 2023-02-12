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

void solve(){
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  forn(i,n) cin >> a[i];

  int ans = 0;
  for (int i = 0; i < (1 << n); i++){
    vector<int> v;
    int sum = 0;
    for (int j = 0; j < n; j++){
      if (i & (1 << j)){
        v.pb(a[j]);
        sum += a[j];
      }
    }
    // Process answer
    int ok = 1;
    if (sum >= s){
      for (auto x: v){
        if (sum - x >= s){
          ok = 0;
        }
      }
      ans = max(ans, ok * (int)v.size() );
    }
  }
  cout << ans << endl;
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
