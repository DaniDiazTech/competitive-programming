// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 
 
typedef pair<int, int> pii;
 
const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;
 
int dp[MAX];
int a[MAX];
void solve(){
  int n, k;
  cin >> n >> k;
  // Indexed at 1
  forn(i,n) cin >> a[i + 1];
  fill(dp, dp + n + 2, oo);
  dp[1] = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= k; j++){
      if (i + j > n) break;
      dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
    }
  } 
  cout << dp[n] << endl;
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