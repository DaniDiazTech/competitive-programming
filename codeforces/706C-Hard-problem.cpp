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
typedef vector<int> vii;

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

// int arr[MAX];
void solve(){
  int n;
  cin >> n;
  int c[n + 1];
  int dp[n + 1][2];
  dp[0][0] = dp[0][1] = 0;
  for (int i=1; i <= n; i++){
    cin >> c[i];
  }
  string prev = "a";
  string rprev;
  string s2;
  for (int i=1; i <= n; i++){
    string s; cin >> s;
    s2 = s;
    rprev = prev;
    reverse(s2.begin(), s2.end());
    reverse(rprev.begin(), rprev.end());

    dp[i][0] = dp[i][1] = oo;

    if (prev <= s){
      dp[i][0] = dp[i - 1][0];
    }
    if (rprev <= s){
      dp[i][0] = min(dp[i - 1][1], dp[i][0]);
    }

    if (prev <= s2){
      dp[i][1] = dp[i - 1][0] + c[i];
    }
    if (rprev <= s2){
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }
    prev = s;
  }
  
  int ans = min(dp[n][0], dp[n][1]);
  if (ans >= oo){
    cout << - 1<< endl;
  }
  else{
    cout << ans << endl;
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
