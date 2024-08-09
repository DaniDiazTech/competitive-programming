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
  vector<char> a(n);
  map<char, int> mp;
  mp['N'] = 0;
  mp['S'] = 1;
  mp['E'] = 2;
  mp['W'] = 3;
  
  vector<char> name = {'R', 'H'};
  vector<vector<int>> count(4);
  for (int i =0 ;i < n; i++){
    count[mp[s[i]]].push_back(i);
  }
  int i = 0 ;
  while (count[0].size() && count[1].size()){
    a[count[0].back()] = name[i];
    a[count[1].back()] = name[i];
    count[0].pop_back();  
    count[1].pop_back();  
    i = (i + 1) % 2;
  }
  while (count[0].size()){
    a[count[0].back()] = name[i];
    count[0].pop_back();
    i = (i + 1) % 2;
  }
  while (count[1].size()){
    a[count[1].back()] = name[i];
    count[1].pop_back();
    i = (i + 1) % 2;
  }

  while (count[2].size() && count[3].size()){
    a[count[2].back()] = name[i];
    a[count[3].back()] = name[i];
    count[2].pop_back();  
    count[3].pop_back();  
    i = (i + 1) % 2;
  }
  while (count[2].size()){
    a[count[2].back()] = name[i];
    count[2].pop_back();
    i = (i + 1) % 2;
  }
  while (count[3].size()){
    a[count[3].back()] = name[i];
    count[3].pop_back();
    i = (i + 1) % 2;
  }

  // cout << "STRING: ";
  // for (auto  x: a) cout << x;
  // cout << endl;

  int rx = 0, ry = 0, hx = 0, hy = 0, ch = 0, cr = 0;
  for (int i =0 ;i < n; i++){
    if (a[i] == 'R'){
      rx += (s[i] == 'N' ? 1 : (s[i] == 'S' ?  -1 : 0));
      ry += (s[i] == 'E' ? 1 : (s[i] == 'W' ?  -1 : 0));
      cr++;
    }
    else{
      hx += (s[i] == 'N' ? 1 : (s[i] == 'S' ?  -1 : 0));
      hy += (s[i] == 'E' ? 1 : (s[i] == 'W' ?  -1 : 0));
      ch++;
    }
  }
  if (hx == rx && hy == ry && ch > 0 && cr > 0 ){
    for (auto  x: a) cout << x;
    cout << endl;
  }
  else{
    cout << no << endl;
  }
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
