// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  
  ll mx = -1e18;
  vector<ll> a(n);
  ll sum = 0;
  for (int i  = 0;i < n; i++){
    cin >> a[i];
    sum += a[i];
  }

  ll cur = -1e18;
  for (int i = 0;i  < n; i++){
    if (cur + a[i] < a[i]) cur = a[i];
    else cur += a[i];
    mx = max(mx, cur);
  }


  ll add = 0, total = 0;
  if (mx > 0){
    // cout << "MX: " << mx << '\n';
    add = mx; 
    total = add;
    k--;
    while (k--){
      add = (add * 2) % mod;
      total = (total + add) % mod;
    }
  }

  ll q = abs((abs(sum)+ mod - 1)  / mod);
  ll ans = (sum + total + q * mod) % mod;

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
