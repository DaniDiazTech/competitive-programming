#include <bits/stdc++.h>
using namespace std;
signed main(){
  string num;
  cin >> num;
  int x,y; cin >> x >> y;
  int numx = stoi(num, 0, x);
  string ans = "";
  while (numx){
    int x = numx % y;
    if (x > 9){
      ans += 'A' + (x - 10);
    }
    else{
      ans += '0' + x;
    }
    numx/=y;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}