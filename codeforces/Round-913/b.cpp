// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int n = s.size();
  vector<pair<int,char>> mn, my;
  for (int i = 0 ;i < n ; i++){
    if (s[i] == 'b'){
      if (mn.size()){
        mn.pop_back();
      }
    }
    else if (s[i] == 'B'){
      if (my.size()){
        my.pop_back();
      }
    }
    else if (s[i] >= 'a'){
      // cout << s[i] << endl;
      mn.push_back({i,s[i]});
    }
    else{
      my.push_back({i, s[i]});
    }
  }
  vector<pair<int, char>> ans;
  for (auto x: mn) ans.push_back(x);
  for (auto x: my) ans.push_back(x);
  sort(ans.begin(), ans.end());
  for (auto x: ans){
    cout << x.second;
  }
  cout << endl;
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
