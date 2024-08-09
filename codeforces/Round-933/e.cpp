// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int INF = 1e8;

void solve(){
  int n, m, ke, d;
  cin >> n >> m >> ke >> d;
  vector<int> ans(n);
  for (int i =0 ;i< n; i++){
    vector<int> a(m), dp(m, INF);
    for (int j = 0;j < m; j++){
      cin >> a[j];
      a[j]++;
    }

    dp[0] = 1;
    multiset<int> s;
    s.insert(dp[0]);
    for (int j = 1; j < m; j++){
      dp[j] = a[j] + (*s.begin());
      if (j >= d + 1){
        auto it = s.find(dp[j - d - 1]);
        s.erase(it);
      }
      s.insert(dp[j]);
    }


    ans[i]= dp[m - 1];
  }

  for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
  int best = 1e7;
  best = ans[ke - 1];
  for (int i = ke; i < n; i++){
    best = min(best, ans[i] - ans[i - ke]);
  }
  cout << best << endl;
}

signed main() {
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
