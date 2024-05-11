// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int n = s.size();
  string k = "kick";
  int c = 0;
  for (int i =0 ;i < (n - k.size() + 1); i++){
    bool f = 1;
    for (int j = 0; j < (int)k.size(); j++){
      if (s[i + j] != k[j]){
        f = 0;
        break;
      }
    }
    if (f) c++;
  }
  cout << c << endl;
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
