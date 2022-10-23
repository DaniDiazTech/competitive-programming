#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
  int n; cin >> n;
  // ll ans = pow(2, n); 
  // Not the way to go
  int base  = 2;
  int ans = 1;

  for (int i = 1; i <= n; i++){
    ans *= base;
    ans %= MOD;
  }
  cout << ans;
}