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

const int MAX = 200;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;
const int mxw  = 1e5;
int dp[100010];
// 2D DP
// Used Weight number of objects
void solve(){
  int n, W;
  cin >> n >> W;
  forn(i,n){
    int w, v;
    cin >> w >> v;
    for (int wa = W  - w; wa >= 0 ; wa--){
      dp[wa + w] = max(dp[wa + w], dp[wa] + v);
    }
  }
  int ans = 0 ;
  for (int i = 0; i <= W; i++){
    ans = max(ans, dp[i]);
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
