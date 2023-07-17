#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool f(ll x, int a, int b, int n){
  return 1LL * (x / a) * (x / b) >= n;
}


int main(){
  int a, b, n; cin >> a >> b >> n;
  // Perform binary search
  ll l = 0, r = 1;
  while (!f(r, a, b, n)){
    r *= 2;
  }

  while ((ll)l + 1 < r){
    ll m = (l + r) >> 1;
    if (f(m, a, b, n)){
      r = m;
    }
    else l = m;
  }
  cout << r << endl;
}