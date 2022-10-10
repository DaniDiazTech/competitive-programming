#include  <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tc; cin >> tc;
  while (tc--){
    int n,m; cin >> n >> m;
    cout << (n / 3)  * (m/3) << endl;
  }
}