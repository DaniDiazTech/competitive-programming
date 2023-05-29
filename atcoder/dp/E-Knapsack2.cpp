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
int w[200], v[200];
void solve(){
  int n, W;
  cin >> n >> W;
  int sum_value = 0;
  forn(i,n){
    cin >> w[i] >> v[i];
    sum_value += v[i];
  }
  fill(dp, dp + sum_value + 5, 1e17);
  dp[0] = 0;
  forn(i,n){
    for (int va = sum_value - v[i]; va >= 0; va--){
      dp[va + v[i]] = min(dp[va + v[i]], dp[va] + w[i]);
    }
    
    forn(i,sum_value + 1){
      cout << dp[i] << " ";
    }
    cout << endl;
  }
  int ans = 0;
  forn(i,sum_value + 1){
    if (dp[i] <= W){
      ans = max(ans, i);
    }
    cout << (dp[i] == 1e17 ? -1 : dp[i]) << " ";
  }
  cout << endl;
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
