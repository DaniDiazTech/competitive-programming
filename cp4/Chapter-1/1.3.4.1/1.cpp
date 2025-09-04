#include <bits/stdc++.h>
using namespace std;

int main(){
  double x; cin >> x;
  int nx  = x;
  int cnt = 3;
  while (nx){
    nx /= 10;
    cnt--;
  }
  int pad = max(0,cnt);
  string pref = string(pad, 's');
  cout << pref << fixed << setprecision(3) << x << endl;
}