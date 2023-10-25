// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll binpow(ll x, ll n){
  if (n == 0) return 1;
  if (n == 1) return x;
  ll half = binpow(x, n / 2);
  return (((half * half) %  mod) * (n % 2 == 1 ? x : 1)) % mod;
}

void solve(){
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    mp[x]++;
  }
  int l = mp.size();
  ll mult[l + 1];
  mult[0] = 1;
  vector<int> a;
  a.push_back(0);

  for ( auto x: mp ){
    a.push_back(x.first);
    mult[a.size() - 1] = x.second;
  }
  for (int i =1; i <=l ; i++){
    mult[i] = (mult[i] * mult[i - 1]) % mod;
  }

  // sliding window
  ll ans = 0 ;
  int i = 1, j = m;
  // cout << "BIN: " <<  binpow(2, 3) << endl;

  while (j < a.size()){
    if (a[j] - a[i] < m){
      // do combinatorics
      // modular inverse
      ll x = (mult[j] * (binpow(mult[i - 1], mod - 2) % mod)) % mod;
      // cout << "Ai: " << a[i] << " Aj: " << a[j] << endl;
      // cout << "X: " <<x << endl;
      ans = (ans + x) % mod;
    }
    i++;
    j++;
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
