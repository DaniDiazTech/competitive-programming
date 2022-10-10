#include <bits/stdc++.h>
using namespace  std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int  t;
  while (cin >>  t){
    if (t == 0) break;
    // Division points
    int n, m; cin >> n >> m;
    while (t--){
      int  x, y; cin >> x >> y;
      if (x == n || y == m) cout << "divisa";
      else if (x > n){
        if  (y > m) cout << "NE";
        else cout << "SE";
      }
      else {
        if  (y > m) cout << "NO";
        else cout << "SO";
      }
      cout << endl;
    }

  }
}