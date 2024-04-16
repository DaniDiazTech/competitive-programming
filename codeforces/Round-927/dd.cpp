// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  // 'C', 'D', 'H', and 'S'
  map<char,int> mp;
  mp['C'] = 0;
  mp['D'] = 1;
  mp['H'] = 2;
  mp['S'] = 3;

  vector<string> a[4];

  char suit; cin >> suit; 
  for (int i =0; i < 2* n; i++){
    string s; cin >> s;
    a[mp[s[1]]].push_back(s);
  }


  for (int i = 0;i < 4; i++){
    sort(a[i].begin(), a[i].end());
  }

  vector<pair<string,string>> v;
  // suit
  while (a[mp[suit]].size() > n){
    pair<string, string> p;
    p.second = a[mp[suit]].back();
    a[mp[suit]].pop_back();
    p.first = a[mp[suit]].back();
    a[mp[suit]].pop_back();
    v.push_back(p);
  }
  // use all suits against other cards

  for (int i =0 ;i < 4; i++){
    // fix parity with suit
    if (i == mp[suit] || a[i].size() % 2 == 0 || a[mp[suit]].size() == 0) continue;

    pair<string, string> p;

    p.second = a[mp[suit]].back();
    a[mp[suit]].pop_back();
    p.first = a[i].back();
    a[i].pop_back();
    v.push_back(p);
  }

  bool f = 1;

  for (int i =0  ;i < 4; i++){
    if (a[i].size() & 1){
      f = 0;
      break;
    }
    while (a[i].size()){
      pair<string, string> p;
      p.second = a[i].back();
      a[i].pop_back();
      p.first = a[i].back();
      a[i].pop_back();
      v.push_back(p);
    }
  }

  if (f){
    for (auto x: v){
      cout << x.first << " " << x.second << '\n';
    }
  }
  else cout << "IMPOSSIBLE\n";
  
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
