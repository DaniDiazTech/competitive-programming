// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> a;
  for (int i =0;i < n; i++){
    ll x; cin >> x;
    a.push_back(x);
  }
  if (n < 3){
    a.push_back(0);
    a.push_back(0);
  }
  int m=a.size();
  ll ans  = 0;
  for (int i = 0;i < m; i++){
    for (int j = i+ 1; j < m; j++){
      for (int k = j + 1; k < m; k++){
        ans  = max(ans, a[i] | a[j] | a[k]);
      }
    }
  }

  cout << ans << endl;
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
