// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 102;

int a[N][N];
bool b[N][N];
short dp[N][N];

bool go(int i, int j){
  if (i == 1 && j == 1) return 1;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = (b[i][j] && (go(i - 1, j) || go(i, j - 1)));
}

void solve(){
  int n, m;
  cin >> n >> m;

  for (int i =1 ;i <= n; i++){
    for (int j =1 ;j <= m; j++){
      cin >> a[i][j];
    }
  }

  int mx = 1;

  int g = __gcd(a[1][1], a[n][m]);

  for (int d = 1 ; d * d <= g; d++){
    if (g % d == 0){
      // Test d
      // Fill B with boolean values

      for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
          b[i][j] = a[i][j] % d == 0;
          dp[i][j] = -1;
        }
      }

      if (go(n, m)){
        mx = max(mx, d);
      }


      // Test g / d
      for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
          b[i][j] = a[i][j] % (g / d) == 0;
          dp[i][j] = -1;
        }
      }
      
      if (go(n, m)){
        mx = max(mx, g / d);
      }
    }
  }

  cout << mx << '\n';
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
