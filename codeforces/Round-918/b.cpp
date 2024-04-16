// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n = 3;
  int a[n][n];
  int row = 0;
  for (int i =0 ;i < n; i++){
    for (int j =0;j < n ;j++){
      char ch; cin >> ch;
      if (ch == '?') a[i][j] = -1, row = i;
      else a[i][j] = ch - 'A';
    }
  }
  vector<bool> b(3);
  for (int j =0;j < 3; j++){
    if (a[row][j] == -1){
      continue;
    } 
    b[a[row][j]] = 1;
  }
  for (int i =0 ;i < 3; i++){
    if (!b[i]) cout << char(i + 'A') << '\n';
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
