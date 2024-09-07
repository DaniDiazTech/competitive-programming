// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll n, a , b;

pair<ll,ll> g(pair<ll,ll> v){
  return { v.first + a * v.second, -a * v.first + v.second  };
}

void solve(){
  cin >> n >> a >> b;
  vector<pair<ll,ll>> p;
  for (int i = 0;i < n; i++){
    ll x, vx, vy; cin >> x >> vx >> vy;
    auto pl = g({vx, vy});
    p.push_back({pl.second, pl.first});
  }
  sort(p.begin(), p.end());
  ll ans = 0;
  ll same = 1, cnt = 1;

  // for (auto x: p){
  //   cout << x.first << " " << x.second << endl;
  // }

  for (int i = 1;i < n; i++){
    if (p[i].first == p[i - 1].first){
      if (p[i].second == p[i - 1].second){
        ans += (cnt - same) * 2;
        same++;
      }
      else{
        ans += cnt * 2;
        same = 1;
      }
      cnt++;
    }
    else{
      cnt = same = 1;
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
