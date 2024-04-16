// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll binpow(ll a, ll b){
  if (b == 0) return 1;
  if (b == 1) return a;
  ll x = binpow(a , b / 2);
  return ( (  (x * x) ) * (b & 1 ? a : 1));
}

void solve(){
  ll s, m; cin >> s >> m;
  ll N = 42;
  ll ans = s;

  for (int k = 2; k <= N; k++){
    ll x = ceil(pow(s, (1.0) / k));
    ll mn = x*k;
    for (int j = 1; j <= k; j++){
      if (binpow(x - 1, j) * binpow(x, k - j) < s) break;
      mn--;
    }

    ans = min(mn + (k - 1) * m, ans);
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
