// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int m = 2 * n; 
  char a[m][m];

  int k = 0, l =0;

  for (int i =0 ;i < n; i++, k+=2){
    l = 0;
    for (int j =0 ;j < n; j++, l +=2){
      a[k][l] = a[k + 1][l] = a[k + 1][l + 1] = a[k][l + 1] = (j % 2 == i % 2 ?  '#': '.' );
    }
  }

  for (int i =0 ;i < m; i++){
    for (int j = 0; j < m; j++){
      cout << a[i][j];
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
