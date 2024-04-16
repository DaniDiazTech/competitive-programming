// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n = 2;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0;i < n; i++){
    for (int j = 0;j < n; j++){
      cin >> a[i][j];
    }
  }

  for (int k = 0; k < 4; k++){
    if (a[0][0] < a[0][1] && a[0][1] < a[1][1] && a[1][0] < a[1][1] && a[0][0] < a[1][0]){
      cout << yes << '\n';
      return;
    }
    vector<vector<int>> b(n, vector<int>(n));
    b[0][0] = a[1][0];
    b[0][1]= a[0][0];
    b[1][1] = a[0][1];
    b[1][0] = a[1][1];
    a = b;
  }
  cout << no << '\n';
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
