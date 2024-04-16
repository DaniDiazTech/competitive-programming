// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, x;
  cin >> n >> x;
  ll a[n];
  for (int i = 0;i < n; i++){
    cin >> a[i];
  }

  ll l = 0, r = 1e12;

  while (l + 1 < r){
    ll m = l + (r - l) / 2;

    ll s = n * m;
    for (int i =0; i < n; i++){
      s -= min(m, a[i]);
    }

    if (s <=x)l =m;
    else r =m;
  }
  cout << l << "\n";
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
