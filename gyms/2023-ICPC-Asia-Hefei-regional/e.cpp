// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;

  map<int, vector<pair<int,int>>> mp;
  for (int i =0 ;i < n; i++){
    for (int j = 0;j < m; j++){
      int c; cin >> c;
      mp[c].push_back({i, j});
    } 
  }
  ll ans = 0;
  for (auto v: mp){
    vector<ll> x, y; 
    for (auto l: v.second){
      x.push_back(l.first);
      y.push_back(l.second);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int k = x.size();

    ll color = 0;
    ll sumx = 0, sumy = 0;

    for (int i = 0; i < k; i++){
      color += i * x[i] - sumx;
      color += i * y[i] - sumy;
      sumx += x[i];
      sumy += y[i];
    }
    ans += 2 * color;
  
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
