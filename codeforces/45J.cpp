/ Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

// L R U D LU LD RU RD
int dr[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dc[] = {-1, 1, 0, 0, -1, -1, 1, 1};

// N rows, M columns
int n, m;
bool valid(int i, int j){
  return i >= 0 && j >= 0 && i < n && j < m;
}

void solve(){
  cin >> n >> m;
  int a[n][m];
  
  int x = 1;
  for (int i = 0; i < n; i++){
    for (int j = i % 2 == 0;j < m; j+=2){
      a[i][j] = x++;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = i & 1;j < m; j+=2){
      a[i][j] = x++;
    }
  }



  for (int i =0 ;i < n; i++){
    for (int j =0;j < m; j++){
      for (int k = 0; k < 4; k++){
        int x = i + dr[k], y = j + dc[k];
        if (valid(x, y)){
          if (abs(a[i][j] - a[x][y]) <= 1){
            cout << "-1\n"; 
            return;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j =0; j < m; j++){
      cout << a[i][j] << ' ';
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
