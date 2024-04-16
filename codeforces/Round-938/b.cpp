// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, c, d; cin >> n >> c >> d;
  vector<ll> v(n * n);
  map<ll, int> mp;
  ll mn = 1e17;
  for (auto &x: v){
    cin >> x;
    mn = min(x, mn);
    mp[x]++;
  }

  ll a[n + 1][n + 1], b[n + 1][n + 1];
  a[0][0] = b[0][0] = mn;
  for (int i = 0; i < n; i++){
    for (int j =0; j < n; j++){
      a[i][j + 1] = a[i][j] + d;
      a[i + 1][j] = a[i][j] + c;
      
      b[i + 1][j] = b[i][j] + c;
      b[i][j + 1] = b[i][j] + d;
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (a[i][j] != b[i][j]){
        cout << no << endl;
        return;
      }
      if (mp[a[i][j]] == 0){
        cout << no << endl;
        return;
      }
      mp[a[i][j]]--;
    }
  }

  cout << yes << endl;

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
