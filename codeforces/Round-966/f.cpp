// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


const int inf = 1e9;

void solve(){
  int n, K;
  cin >> n >> K;

  vector<pair<int,int>> v;

  for (int i =0 ;i < n; i++){
    int a, b; cin >> a >> b;
    v.push_back({min(a, b), max(a, b)});
  }

  int m = 1000;
  // i, j = min op to achieve j value
  vector<vector<int>> dp(n + 2, vector<int>(2 * m, inf));
  dp[0][0] = 0 ;

  for (int i =0 ; i < n; i++){
    for (int j = 0;j <= K; j++){
      if (j == 0) dp[i][j] = 0;
      auto &l = dp[i][j];
      dp[i + 1][j] = min(l, dp[i + 1][j]);

      if (l == inf){
        continue;
      }
      
      // Do the transition:
      int x = 0; 
      int k = 0; 

      int r = v[i].second, c = v[i].first;
      while (r > c){
        r--;
        k++;
        x += c;
        dp[i + 1][j + k] = min(dp[i + 1][j + k], l + x);
      }

      while (r || c){
        // first row
        // r == c
        x += r;
        k++;

        dp[i + 1][j + k] = min(dp[i + 1][j + k], l + x);
        r--;
        c--;

        k++;
        x += c;
        dp[i + 1][j + k] = min(dp[i + 1][j + k], l + x);
      }
    }
  }

  int ans = inf;
  for (int i = K; i < m; i++){
    ans = min(ans, dp[n][i]);
  }

  cout << (ans == inf ? -1 : ans) << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
