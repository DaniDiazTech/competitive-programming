// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll binpow(ll a, ll b){
  if (b == 0) return 1;
  if (b == 1) return a;
  ll x = binpow(a, b / 2);
  return x * x * (b & 1 ? a : 1);
}

void solve(){
  ll a,b,l; cin >> a >> b >> l;
  ll lim = 20;

  set<ll> s;
  for (ll x = 0; x <= lim; x++){
    ll ax = binpow(a, x);
    if (ax > l) break;
    for (ll y = 0; y <= lim; y++){
      ll by = binpow(b, y);
      if (by > l) break;
      ll div = ax * by;
      if (l % div == 0){
        s.insert(l / div);
      }
    }
  }
  cout << s.size() << '\n';
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
