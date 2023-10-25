// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e5 + 10;

ll dp[N];


void solve(){
  int a, b;
  cin >> a >> b;
  cout << (dp[b] - dp[a - 1] + (mod)) % mod << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1, k ;

  cin >> tc >> k ;

  for (int i= 0; i < N; i++){
    if (i < k){
      dp[i] = 1;
      continue;
    }
    dp[i] = (dp[i - 1]+ dp[i - k]) % mod;
  }
  
  for (int i= 1; i < N; i++){
    dp[i]= (dp[i - 1] + dp[i]) % mod;
  }

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
