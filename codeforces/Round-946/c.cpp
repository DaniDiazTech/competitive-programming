// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> v;
  int a[n];
  for (int i =0 ;i < n;i++) cin >> a[i];
  for (int i = 0;i < n - 2; i++){
    v.push_back({a[i], a[i + 1], a[i + 2]});
  }
  ll ans = 0;
  for (int k = 0; k< 3; k++){
    map<pair<int,int>, map<int, ll>> mp;
    for (auto x: v){
      pair<int,int> p = {x[(k + 1) % 3], x[(k + 2) % 3]};
      // cout << "K: " << k << " pair: " << p.first << " " << p.second << endl;
      mp[p][x[k]]++;
    }
    for (auto x: mp){
      ll c = 0;
      ll sum = 0;
      for (auto y: x.second){
        sum += y.second; 
        c += ((y.second) * (y.second - 1)) / 2;
      }
      ans += (sum  * (sum - 1) / 2) - c;
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
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
