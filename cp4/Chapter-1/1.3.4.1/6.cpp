// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v; cin >> n >> v;
  int a[n];for(int i =0 ;i < n; i++) cin >> a[i];
  int l = -1, r = n;
  while (l +1 < r){
    int m = (l + r) / 2;
    if (a[m] > v){
      r = m;
    }
    else l = m;
  }
  if (l == -1 || a[l] != v) cout << "NO" << endl;
  else cout << "YES" << endl;
}
