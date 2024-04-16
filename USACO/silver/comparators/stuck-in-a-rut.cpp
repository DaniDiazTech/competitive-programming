// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> a[n];

  vector<int> dp(n, 0);
  vector<pair<pair<ll,ll>, int>> east, north;
  // time, {stopped, stopper}
  vector<pair<ll,pair<int,int>>> t;
  for (int i =0;i < n; i++){
    char op; ll x, y; cin >> op >> x >> y; 
    a[i] = {op == 'N', x, y};
    if (op == 'E'){
      east.push_back({{x,y}, i});
    }
    else{
      north.push_back({{x,y}, i});
    }
  }

  vector<bool> vis(n);

  sort(east.begin(), east.end(), [&](pair<pair<ll,ll>,int> &a, pair<pair<ll,ll>, int> &b){
    return a.first.second < b.first.second;
  }
  );
  sort(north.begin(), north.end());

  // every pair east, north
  for (auto a: east){
    for (auto b: north){
      ll dx = b.first.first - a.first.first;
      ll dy = b.first.second - a.first.second;

      if (!vis[a.second] && !vis[b.second] && dy < 0 && dx > 0){
        dy = abs(dy);
        if (dy > dx){
          vis[b.second] = 1;
          dp[a.second] += 1 + dp[b.second];
        }
        if (dy < dx){
          vis[a.second] = 1;
          dp[b.second] += 1 + dp[a.second];
        }
      }
    }
  }
  for (auto x: dp) cout << x << '\n';
  
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
