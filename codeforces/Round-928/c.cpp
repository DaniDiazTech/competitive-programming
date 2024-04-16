// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 2e5 + 10;

ll dp[N];

void solve(){
  int n;
  cin >> n;
  cout << dp[n] << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  for (int i = 1;i < N; i++){
    string x = to_string(i);
    ll cnt   = 0;
    for (auto l: x){
      cnt += l - '0';
    }
    dp[i] = dp[i - 1] + cnt;
  }


  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
