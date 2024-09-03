// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string s; cin >> s;
  vector<pair<int,int>> a;
  a.push_back({-1, 0});
  for (int i = 0;i < n; i++){
    if (a.back().first == (int)(s[i] - 'a')){
      a.back().second++;
    }
    else{
      a.push_back({s[i] - 'a', 1});
    }
  }

  // for (auto x: a){
  //   cout << x.first << " " << x.second <<  endl;
  // }
  // cout << endl;

  int ans = 0;
  for (int i = 1;i < (int)a.size(); i++){
    ans += a[i].second >= 2;
  }

  ans += (int)a.size() - 2; 
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
