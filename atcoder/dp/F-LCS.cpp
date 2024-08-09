// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 3005;
string a, b;
int n, m;

int dp[N][N];

int go(int i, int j){
  if (i == n || j == m) return 0;
  if (dp[i][j] !=-1) return dp[i][j];
  return dp[i][j] = max(go(i + 1, j + 1) + (a[i] == b[j]), max(go(i + 1, j), go(i, j + 1)));
}

void solve(){
  cin >> a >> b;
  n = a.size(), m = b.size();
  memset(dp, -1, sizeof dp);
  cout << go(0, 0) << endl;
  for (int i =0 ;i < n; i++){
    for (int j = 0;j < m; j++){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
