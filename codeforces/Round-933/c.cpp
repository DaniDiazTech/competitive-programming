// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int m;
  cin >> m;
  string s; cin >> s;

  int i = 0;
  int mn = 0;

  int n = m;
  // starting character
  while (i < n){
    string a, b;
    for (int k = 0; k < 5 && i + k < n; k++){
      if (k < 3)
        a += s[i + k];

      b += s[i + k];
    }
    if (b == "mapie"){
      mn++;
      i += 5;
    }
    else if (a == "map" || a == "pie"){
      mn++;
      i += 3;
    }
    else{
      i++;  
    }
  }
  cout << mn << endl;
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
