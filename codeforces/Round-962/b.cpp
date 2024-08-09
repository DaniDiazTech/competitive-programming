// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  char a[n][n];
  for (int i =0;i < n; i++){
    for (int j = 0;j < n; j++) cin >> a[i][j];
  }

  char b[n / k][n / k];

  for (int i =0 ; i < n; i+= k){
    for (int j = 0; j < n; j += k){
      b[i / k][j / k] = a[i][j];
    }
  }

  for (int i =0 ;i < n / k; i++){
    for (int j =0 ; j < n / k; j++){
      cout << b[i][j];
    }
    cout << endl;
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
