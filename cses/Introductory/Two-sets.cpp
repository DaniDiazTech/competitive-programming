// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  #if LOCAL 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ll n; cin >> n;
  ll total = ((n) * (n + 1)) >> 1; 

  if (total & 1){
    cout << "NO" << endl;
    return 0;
  }

  ll s = 0;
  set<ll> s1;
  set<ll> s2;
  for (ll i = 1; i <= n; i++) s2.insert(i);
  for (ll  i = n; i >= 1; i--){
    if (s == (total / 2)) break;
    if (s + i > (total / 2) ){
      continue;
    }
    else{
      s2.erase(i);
      s1.insert(i);
      s += i;
    }
  }
  cout << "YES" << endl;
  cout << s1.size() << endl;
  for (auto x: s1) cout << x << " ";
  cout << endl << s2.size() << endl;
  for (auto x: s2) cout << x << " ";
  cout << endl;
}