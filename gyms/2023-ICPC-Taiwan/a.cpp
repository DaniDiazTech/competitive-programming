// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int m = stoi(s.substr(5, 2)), d = stoi(s.substr(8, 2));
  if (m < 9){
    cout << "GOOD";
  }
  else if (m == 9 && d <= 16){
    cout << "GOOD";
  }
  else{
    cout << "TOO LATE" << '\n';
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
