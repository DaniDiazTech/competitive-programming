// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m, x;
  cin >> n >> m >> x;
  x--;
  vector<vector<bool>> dp(m + 1, vector<bool>(n));
  dp[0][x] = 1;
  for (int i =0 ;i < m; i++){
    int r;
    char ch;
    cin >> r >> ch;
    for (int j = 0; j < n; j++){
      if (dp[i][j]){
        if (ch == '0'){
          dp[i + 1][(j + r) % n] = 1;
        }
        else if (ch == '1'){
          dp[i + 1][( ( (j - r) % n) + n) % n] = 1;
        }
        else{
          // both
          dp[i + 1][(j + r) % n] = 1;
          dp[i + 1][( ( (j - r) % n) + n) % n] = 1;
        }
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i++){
    if (dp[m][i]) ans.push_back(i + 1);
  }
  cout << ans.size() << '\n';
  for (auto x : ans)  cout << x << " ";
  cout << '\n';
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
