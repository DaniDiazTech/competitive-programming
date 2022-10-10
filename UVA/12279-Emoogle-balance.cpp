#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int cs = 1;
  while (cin >> n){
    if (n == 0) break; 
    int x  = 0, y = 0;
    for (int i = 0; i < n; i++){
      int l; cin >> l;
      if (l == 0) y++;
      else x++;
    }
    cout << "Case " << cs << ": " << (x - y) << endl;
    cs++;
  }
}