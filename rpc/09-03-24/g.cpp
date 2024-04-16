// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n = 4;
  vector<pair<ll,ll>> a(n);
  vector<ll> sides(n);
  vector<long double> slope(n);
  for (auto &c: a) cin >> c.first >> c.second;

  for (int i = 0;i < n; i++){
    // with next
    int j = (i + 1) % n;
    sides[i] = (a[j].first - a[i].first) * (a[j].first - a[i].first) + (a[j].second - a[i].second) * (a[j].second - a[i].second);

    // slope i
    if (a[j].first - a[i].first == 0){
      slope[i] = -1;
    }
    else{
      slope[i] = (a[j].second - a[i].second) / (a[j].first - a[i].first);
    }

  }
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
