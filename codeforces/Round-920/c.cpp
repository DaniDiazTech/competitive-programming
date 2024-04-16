// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, f, a, b;
  cin >> n >> f >> a >> b;

  vector<ll> v(n + 1);
  for (int i = 1;i <= n; i++){
    cin >> v[i];
  }

  for (int i = 1;i <= n; i++){
    ll x = min(b, (v[i] - v[i - 1]) * a);
    f -= x;
    if (f <= 0){
      cout << no << '\n';
      return;
    }
  }

  cout << yes << '\n';

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
