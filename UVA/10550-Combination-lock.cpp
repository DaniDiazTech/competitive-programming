#include <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  string s;
  while (getline(cin, s)){
    if (s == "0 0 0 0") break;
    stringstream x(s);
    int n, m, k, l;
    x >> n >> m >> k >> l;
    int ans = (3 * 360) + 9 * ((n - m + 40) % 40 + (k - m  + 40) % 40 +  (k - l + 40) % 40);
    cout << ans << endl;
  }
}