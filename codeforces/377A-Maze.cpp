// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

// L R U D
int dr[] = {0, 0 , -1, 1};
int dc[] = {-1, 1 , 0, 0};

const int N= 510;
int a[N][N];
bool vis[N][N];

int n, m, k, available = 0;
bool valid(int i , int j ){
  return (i >=0 && i < n && j >=0 && j < m && a[i][j] != 2);
}



void dfs(int i ,int j){
  if (available == 0) return;
  a[i][j] = 1;
  vis[i][j] = 1;
  available--;
  for (int l = 0; l <4 ; l++){
    int x = dr[l] + i;
    int y = dc[l] + j;
    if (valid(x,y) && !vis[x][y])
      dfs(x, y);
  }
}

void solve(){
  cin >> n >> m >> k;


  pair<int, int> p;
  available = n * m - k;
  for (int i = 0 ; i <n ;i++){
    for (int j = 0; j < m; j++){
      char x; cin >> x;
      if ( x== '#' ){
        a[i][j] = 2 ;
        available--;
      }
      else{a[i][j]=3; p = {i, j};}
    }
  }
  dfs(p.first, p.second);

  for (int i =0 ; i < n; i++){
    for (int j = 0; j < m ;j++){
      if (a[i][j] == 3){
        cout << 'X';
      }
      else if (a[i][j] == 2) cout << '#';
      else cout << '.';
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