// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 1e6;
ll a[N];
ll n, b, x;
ll f(ll o){
  ll k = o;
  ll ret = 0; 
  for (int i = 0; i < n; i++){
    k = min(o, a[i]);
    ll fl = a[i] / k, cl = (a[i] + k - 1 ) / k, md = a[i] % k;
    ret += ((md -1 ) * md / 2) * (cl  * cl) + ((k - md) * (k - md - 1) / 2) * (fl * fl) + ((k - md) * md) * (fl * cl);
  }
  ret *= b;
  ret -= x * (o - 1);

  return ret;
}

void solve(){
  cin >> n >> b >> x;
  for (int i =0 ;i < n; i++) cin >> a[i];

  ll ans = 0;  
  ll l = 1, r = 1e6;

  while (l + 3 < r){
    ll m1 = l + (r - l) / 3; 
    ll m2 = r - (r - l) / 3;

    if (f(m1) > f(m2)){
      r = m2;
    }
    else{
      l = m1;
    }
  }

  for (ll i = l; i <= r; i++){
    ans = max(f(i), ans);
  }


  cout << ans << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
