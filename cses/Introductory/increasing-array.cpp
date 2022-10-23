#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++){
    if (a[i - 1] > a[i]){
      ans += a[i - 1] - a[i];
      a[i] = a[i - 1];
    }
  }
  cout << ans;

}