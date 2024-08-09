// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 2e5 + 10;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n +  2);
  vector<vector<int>> dp(n + 2, vector<int>(2, - 1));
  for (int i = 0;i < n; i++) cin >> a[i];
  
  function<int(int, int)> go = [&](int i, bool turn){
    if (i >= n) return 0; 
    auto &l = dp[i][turn];
    if (l !=-1) return l;
    return l = (a[i] && turn) + min(go(i + 1, !turn), (a[i + 1] && turn) + go(i + 2, !turn));
  };

  cout << go(0, 1) << '\n';

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
