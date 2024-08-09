// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;


// Other pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int inf = 1e7;

const int N = 501;
vector<vector<int>> a(26);
string s;
int n, k;

int dp[N][N][N];

int go(int l, int r, int k){
  if (r - l + 1 < k) return inf;
  if (k <= 1) return 0;

  auto &x = dp[l][r][k];
  // cout << l << " " << r << " " << k << endl;
  if (x != inf) return x;
  if (r - l + 1 >= 2)
    x = (s[l] != s[r]) + go(l + 1, r-1, k - 2);
  x = min(x, min(go(l + 1, r, k), go(l, r - 1, k)));
  return x;
}


void solve(){
  cin >> n  >> k >> s;

  for (int i = 0;i < n; i++)
    for (int j =0 ;j < n; j++)
      for (int l = 0; l<= n; l++) dp[i][j][l] = inf;

  cout << go(0,n - 1, k) << '\n';
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
