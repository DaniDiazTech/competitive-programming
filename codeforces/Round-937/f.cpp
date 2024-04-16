// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll a,b,c;
  cin >>a >> b >> c;
  if (a != c - 1){
    cout << "-1\n";
    return;
  }
  if (a == 0){
    cout << b<< endl;

  }
  else{
    ll x = ceil(log2(c));    
    ll y = b - ((1 << x) - c);
    ll ans = x + (y + c - 1) / c ;
    cout << ans << '\n';
  }
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
