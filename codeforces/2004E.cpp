// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N  = 1e7 + 10;
vector<int> dp(N, N);

void solve(){
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0;i < n; i++){
    int x; cin >> x;
    ans ^= dp[x];
  }
  cout << (ans == 0 ? "Bob" : "Alice") << endl;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  dp[0] = 0;
  dp[1] = 1;
  for (ll j = 2; j < N; j+=2){
    dp[j] = 0;
  }
  int p = 1;
  for (ll i = 3; i < N; i++){
    if (dp[i] == N){
      dp[i] = ++p;
      for (ll j = i * i; j < N; j+=i){
        dp[j] = min(dp[j], dp[i]);
      } 
    }
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
