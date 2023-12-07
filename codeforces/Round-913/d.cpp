// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  ll a[n][2];
  for (int i =0 ; i < n; i++){
    cin >> a[i][0] >> a[i][1];
  }

  ll l = -1, r = 2e9;
  while (l + 1 < r){
    ll m = (l + r) / 2;

    // simulate 
    pair<ll, ll> range = {0, 0};
    bool f = 1;
    for (int i =0 ;i  < n ; i++){
      if (range.first > a[i][1]){
        // current is to right
        // jump to left
        ll dis = abs(range.first - a[i][1]);
        if (dis > m){
          f = 0;
          break;
        }
        range.first = max(range.first - m, a[i][0]);
        range.second = a[i][1];

      }
      else if (range.second < a[i][0]){
        // jump to right
        ll dis = abs(a[i][0] - range.second);
        if (dis > m){
          f = 0;
          break;
        }
        range.first = a[i][0];
        range.second = min(range.second + m, a[i][1]);

      }
      else{
        // Inside
        range.first = max(range.first - m, a[i][0]);
        range.second = min(range.second + m, a[i][1]);
      }
    }
    if (f) r = m;
    else l = m;
  }
  cout << r << endl;
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
