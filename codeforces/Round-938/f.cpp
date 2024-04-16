// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 202;
int dp[N][N][N];

void solve(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  int ans = dp[a][b][c];
  ans += d / 2;
  cout << ans << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        if (i == 0 && j == 0 && k == 0) continue;
        dp[i][j][k] = ((i & 1) ^ ((j & 1)  * 2) ^ ((k & 1) * 3)) == 0;
        dp[i][j][k] += max((i == 0 ? 0: dp[i - 1][j][k]),  
          max((j == 0 ? 0 : dp[i][j - 1][k]), (k == 0 ? 0 : dp[i][j][k - 1])) 
        );
      }
    }
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
