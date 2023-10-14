// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, p;
  cin >> n >> p;
  int a[2][n];
  for (int j = 0;j < 2; j++){
    for (int i = 0; i < n; i++){
      cin >> a[j][i];
    }
  }
  // 
  vector<pair<int,int>> v;
  vector<bool> vis(n);
  for (int i =0; i < n; i++){
    v.push_back({a[1][i], a[0][i]});
  }
  sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int,int> &b){
    return (a.first == b.first ? a.second > b.second : a.first < b.first);
  });
  ll ans= 0;
  queue<pair<ll, ll>> q;
  ll s = 0;
  ll i;
  for (i = 0; i < n ; i++){
    if (s >= n - i){
      break;
    }
    ans += p;
    if (v[i].first < p){
      q.push(v[i]); 
      s += v[i].second;
    }
  }
  // cout << "BEFORE: " << ans << endl;
  // necessary
  s = min(s, n - i);
  while (!q.empty() && s > 0 ){
    auto pi = q.front();
    q.pop();
    ans += pi.first * min(s, pi.second);
    s -= pi.second;
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
