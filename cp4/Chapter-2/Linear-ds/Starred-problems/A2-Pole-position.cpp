#include <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  while (cin >> n && n != 0){
    vector<int> v(n);
    bool f = 1;
    for (int i = 0 ;i < n; i++){
      int car, pos; cin >> car >> pos;
      int l = pos + i;
      if (l >= 0 && l < n && v[l]  == 0){
        v[l] = car;
      }
      else{
        f = 0;
      }
    }

    if (f){
      for (int i =0; i <n ; i++){
        if (i > 0 )
          cout << " ";
        cout << v[i];
      }
    }
    else cout << -1;
    cout << '\n';
  }
}