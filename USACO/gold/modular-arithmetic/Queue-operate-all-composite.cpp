// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const string yes = "YES", no = "NO";

ll binpow(ll a, ll b){
  ll ans = 1;
  while (b){
    if (b & 1 ) ans =(ans * a) % mod;
    a = (a * a) % mod;
    b/=2;
  }
  return ans;
}

ll inv(ll a){
  return binpow(a, mod - 2);
}

void solve(){
  int q;
  cin >> q;
  deque<pair<ll, ll>> dq;
  ll C =1, D = 0;

  while (q--){
    int t; cin >> t;
    if (t == 0){
      ll a, b;
      cin >> a >> b; 
      dq.push_back({a, b});
      D = (b + (a * D) % mod) % mod;
      C = (C * a) % mod;
    }
    if (t == 1){
      // Remove
      ll a = dq.front().first , b = dq.front().second;
      dq.pop_front();

      C = (C * inv(a)) % mod;
      D = ((D - ((C * b)% mod)) + mod) % mod;
    }
    if (t == 2){
      ll x; cin >> x;
      ll ans = ( ( (C * x) % mod) + D) % mod;
      cout << ans << '\n';
    }
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
