// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

/*
Use with caution, may cause precision errors
with floats
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target ("avx,tune=native")

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6;
int phi[N + 1];
ll dp[N + 1];

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  for (int i = 0;i <= N; i++){
    phi[i] = i;
  }

  for (int i = 2; i <= N; i++){
    if (phi[i] == i){
      for (int j = i; j <= N; j+=i){
        phi[j] -= phi[j] / i;
      }
    }
  }

  for (int d = 1; d <= N; d++){
    for (int j = 2; j * d <= N; j++){
      dp[j * d] += phi[j] * d;
    }
  }

  for (int i = 1; i <= N; i++) dp[i] += dp[i - 1];

  int n; 
  while (cin >> n){
    if (n == 0) break;
    cout << dp[n] << '\n';
  }

}
