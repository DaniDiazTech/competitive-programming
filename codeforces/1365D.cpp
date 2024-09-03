// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


// U D L R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


void solve(){
  int n, m;
  cin >> n >> m;

  char a[n][m];
  auto in  = [&](int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  vector<pair<int,int>> g, b;

  for (int i= 0 ;i < n; i++){
    for (int j =0 ;j < m; j++){
      cin >> a[i][j];
      if (a[i][j] == 'G'){
        g.push_back({i,j});
      }
      else if (a[i][j] == 'B'){
        b.push_back({i,j});
      }
    }
  }

  if (g.empty()){
    cout << yes << endl;
    return;
  }

  for (auto p: b){
    int i = p.first, j = p.second;
    for (int k = 0; k < 4; k++){
      int x = i + dr[k], y = j + dc[k];
      if (in(x, y)){
        if ((x == n - 1 && y == m - 1) || a[x][y] == 'G'){
          cout << no << endl;
          return;
        }
        else{
          if (a[x][y] != 'B'){
            a[x][y] = '#';
          }
        }
      }
    }
  }

  vector<vector<bool>> vis(n, vector<bool>(m));
  queue<pair<int,int>> q;
  q.push({n - 1, m -1});
  vis[n - 1][m - 1] = 1;
  while (q.size()){
    auto pr = q.front(); 
    q.pop();
    int i = pr.first, j = pr.second;
    for (int k = 0; k < 4; k++){
      int x = i + dr[k], y = j + dc[k];
      if (in(x, y) && !vis[x][y] && (a[x][y] == '.' || a[x][y] == 'G')){
        vis[x][y] = 1;
        q.push({x,y});
      }
    }
  }

  for (auto p: g){
    if (!vis[p.first][p.second]){
      cout << no << endl;
      return;
    }
  }

  cout << yes << endl;

  
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
