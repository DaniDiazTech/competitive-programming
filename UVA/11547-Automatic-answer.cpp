#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t; cin >> t;
  while (t--){
    ll n; cin >> n;
    ll ans  = (( (( (n * 567) / 9) + 7492) * 235) / 47) - 498;
    cout << to_string(ans).substr(to_string(ans).size() - 2, 1) << endl;
  }
}