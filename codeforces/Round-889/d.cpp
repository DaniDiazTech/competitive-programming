// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 2e5 + 100;

void solve(){
  int n;
  cin >> n;
  vector<ll> a(N + 10), p(N + 10);
  for (int i = 1;i <= n; i++){
    cin >> a[i];
  }
  bitset<N + 10> dp;
  dp[1] = 1;
  for (int i = 1; i <= 2 * n; i++){
    p[i] = a[i] + p[i - 1];
  } 
  ll ans = 0;
  for (int i = 1;i <= n;i++){
    // Eliminates ith bit (sets ith bit to zero)
    // Then returns to previous state and runs a[i] shifts
    dp |= (dp >> i << i + a[i]);
  }
  for (int i = 1; i < N; i++){
    if (dp[i]){
      ans = max(ans, p[i] - i + 1);
    }
  }
  cout << ans << endl;
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
