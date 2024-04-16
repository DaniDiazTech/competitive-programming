// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  string l;
  l.push_back(s[0]);
  l.push_back(s[1]);

  int x = stoi(l);
  if (l >= "12"){
    // Pm
    string p = to_string(x - 12);
    if (p.size() == 1){
      p = "0" + p;
    }
    cout << ((x == 12 ? "12" : p) + s.substr(2));
    cout << " PM\n";
  } 
  else{
    // AM
    cout << ((x ==0 ? "12" : l) + s.substr(2));
    cout << " AM\n";
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
