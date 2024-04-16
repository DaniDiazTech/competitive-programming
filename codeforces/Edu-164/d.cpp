// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const string yes = "YES", no = "NO";

const int N = 5005;
vector<int> a;
ll dp[N][N];
int n;

ll go(int i, int j){
  if (i == n) return 0;
  if (dp[i][j] != -1) return dp[i][j]; 

  dp[i][j] = (j < a[i] ? a[i] : (j + a[i] + 1) / 2) + go(i + 1, j + a[i]); 
  dp[i][j] %= mod;
  dp[i][j] += go(i + 1, j);
  dp[i][j] %= mod;
  return dp[i][j];
}

void solve(){
  cin >> n;
  memset(dp, -1 , sizeof dp);
  for (int i = 0;i < n; i++){
    int x; cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  cout << go(0, 0) << endl;
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
