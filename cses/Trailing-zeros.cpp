#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int fact(int n){
  if (n == 1) return 1;
  return fact(n - 1) * n;
}
int32_t main(){
  int n;
  cin >> n;
  int ans = 0;
  while (n){
    n /= 5;
    ans += n; 
  }
  cout << ans << endl;
}