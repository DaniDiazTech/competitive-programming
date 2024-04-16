// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  char a[n][n];
  pair<int,int> f, last;
  for (int i =0 ;i < n; i++){
    for (int j =0 ; j < n; j++){
      cin >> a[i][j];
      if (a[i][j] == '1'){
        f = {i, j};
      }
    }
  }
  
  for (int i= n- 1; i>=0; i--){
    for (int j =0 ;j < n; j++){
      if (a[i][j] == '1'){
        last = {i, j};
      }
    }
  }

  int must = 1;
  bool uok = 1, dok  = 1;
  // Check upper triangle
  for (int i = f.first; i < n; i++){
    int cnt = 0;
    for (int j =0 ;j < n; j++){
      cnt += a[i][j] == '1'; 
    }
    if (cnt != must && (cnt != 0)){
      uok = 0;
      break;
    }
    must += 2;
  }

  must = 1;
  for (int i = last.first; i>=0; i--){
    int cnt = 0;
    for (int j =0 ;j < n; j++){
      cnt += a[i][j] == '1'; 
    }
    if (cnt != must && (cnt != 0)){
      dok = 0;
      break;
    }
    must += 2;
  }

  if (uok || dok){
    cout << "TRIANGLE";
  }
  else cout << "SQUARE";

  cout << '\n';
  

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
