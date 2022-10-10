#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin >> t;
  for (int i = 1; i <= t; i++){
    cout << "Case " << i << ": ";
    set<int> s;
    int x, y, z; cin >> x >> y >> z;
    s.insert(x);
    s.insert(y);
    s.insert(z);
    auto it  = s.begin();
    it++;
    cout << *it << endl;
  }
}