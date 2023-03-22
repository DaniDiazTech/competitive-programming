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

int a[MAX + 10], dp[MAX + 10];

void solve(){
  int n;
  cin >> n;
  int mxn = 0;
  forn(i,n){
    int x, b; cin >> x >> b;
    a[x] = b;
    mxn = max(mxn, x);
  }
  int mx = -1;
  for (int i = 0; i <= mxn; i++){
    if (a[i] == 0){
      if (i - 1 < 0){
        dp[i] = 0;
      }
      else{
        dp[i] = dp[i - 1];
      } 
    }
    else{
      int ind = i - 1 - a[i];
      if (ind < 0){
        dp[i] = 1;
      }
      else{
        dp[i] = dp[ind] + 1;
      }
    }
    mx = max(mx, dp[i]);
  }
  cout << n - mx << endl;
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
