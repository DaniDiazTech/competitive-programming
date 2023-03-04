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

int a[MAX];
void solve(){
  int n;
  cin >> n;
  for (int i = 1; i < n; i++){
    int cnt = 0;
    for (int j = 1; j * j <= i; j++){
      if (i % j == 0){
        // cout << i << " DIV: " << j << " and " << (i / j) << endl;
        if (j != (i / j)){
          cnt++;
        }
        cnt++;
      }
    }
    a[i] = cnt;
  }
  int ans = 0;

  for (int i = 1; i < n; i++){
    int res = n - i;
    ans += a[i] * a[res];
    // cout << i << ' ' << res << " : " << ans << endl; 
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
