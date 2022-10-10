#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    int mn = 110, mx = -1;
    for (int i = 0; i < n; i++){
      int x; cin >> x;
      mn = min(mn, x);
      mx = max(mx, x);
    }
    cout << 2 * (mx - mn) << endl;
  }
}