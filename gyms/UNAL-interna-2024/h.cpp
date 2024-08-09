// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

bool in(pair<ll,ll> p, ll x){
  return p.first <= x && x <= p.second;
}

void solve(){
  string s;
  cin >> s;
  ll c, m, d;
  cin >> c >> m >> d;

  string notdone = "Think about it, you can do it!";

  ll x = c + d;
  ll INF = 1e18;
  map<pair<ll, ll>, string> mp;
  mp[{-INF, 1199}] = "newbie";
  mp[{1200, 1399}] = "pupil";
  mp[{1400, 1599}] = "specialist";
  mp[{1600, 1899}] = "expert";
  mp[{1900, 2099}] = "candidate master";
  mp[{2100, 2399}] = "master";
  mp[{2400, INF}] = "grandmaster";
  

  if (m >= x){
    cout << notdone;
  }
  else{
    string before, now;
    for (auto key: mp){
      if (in(key.first, m)) before = key.second;
      if (in(key.first, x)) now = key.second;
    }
    if (before == now) cout << notdone;
    else cout << now;
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
