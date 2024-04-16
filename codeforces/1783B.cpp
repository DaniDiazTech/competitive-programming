// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n; cin >> n;
  int a[n][n]; 
  int x = 1, y = n * n;
  bool f = 1;
  for (int i = 0;i < n; i++){
    for (int j =0 ; j < n; j++){
      if (f){
        a[i][j] = x;
        x++;
      }
      else{
        a[i][j] = y;
        y--;
      }
      f = !f;
    }
  }

  for (int i = 0;i < n; i++){
    for (int j =0 ; j < n; j++){
      cout << a[i][(i & 1 ? n - j - 1 : j)] << " ";
    }
    cout << '\n';
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
