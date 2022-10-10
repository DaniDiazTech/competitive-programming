#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin >> t;
  for (int i =1; i <= t; i++){
    int l,w,h; cin >> l >> w >> h;
    cout << "Case " << i << ": ";
    if (l <= 20 && w <= 20 && h <= 20) cout << "good";
    else cout << "bad";
    cout << endl;
  }
}