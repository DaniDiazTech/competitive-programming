// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


ll binpow(ll a, ll b){
  if (b == 0) return 1ll;
  if (b == 1) return a;
  ll x =binpow(a, b / 2);
  return ( ((x * x) % mod) * (b & 1 ? a : 1) ) % mod;
}

void solve(){
  ll n;
  cin >> n;
  vector<ll> a(n + 1), s(n + 1), p(n + 1);

  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++){
    s[i]+=s[i - 1];
    s[i]+=a[i];
    s[i] %= mod;

    p[i]+=p[i -1] ;
    p[i]+= s[i - 1] * a[i];
    p[i] %= mod;
  }

  ll div = binpow((n * (n - 1) / 2) % mod, mod - 2);
  cout << (p[n] * div) % mod << endl;
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
