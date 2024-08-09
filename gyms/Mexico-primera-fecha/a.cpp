// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e4 + 2;
vector<vector<int>> dp(N, vector<int>(N, - 1));
int a[N];
int n;

int go(int l, int r){
  if (l >= r) return 1e7;
  if (r == l + 1) return abs(a[l] - a[r]);
  if (dp[l][r] != - 1) return dp[l][r];
  return dp[l][r]= min(abs(a[l] - a[r]), min(go(l + 1, r), go(l, r - 1)));
}

void solve(){
  cin >> n;
  for (int i =0 ;i < n; i++){
    cin >> a[i];
  }
  go(0, n - 1);
  int q;
  cin >> q;

  while (q--){
    int l , r; cin >> l >> r; 
    l--, r--;
    cout << go(l, r) << '\n';
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
