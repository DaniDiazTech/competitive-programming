// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
// L R U D
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void solve(){
  int n, m;
  cin >> n >> m;
  // 1 -> #

  int N = n + 7;
  int M = m + 7;

  vector<vector<int>> a(N, vector<int>(M)), p(N, vector<int>(M)), T(N, vector<int>(M)), ids(N, vector<int>(M)); 
  vector<vector<bool>> vis(N, vector<bool>(M)), v(N, vector<bool>(M));

  vector<int> R(N), C(M);

  int id = 1; 

  for (int i = 1;i <= n; i++){
    for (int j = 1; j <= m; j++){
      char ch ;
      cin >> ch;
      a[i][j] = (ch == '#');
    }
  }

  function<bool(int, int)> inside = [&](int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  function<int(int, int)> dfs = [&](int r, int c){
    v[r][c] = 1;
    ids[r][c] = id;

    T[r][c] = 1;
    for (int k = 0; k < 4; k++){
      int x = r + dr[k], y = c + dc[k];
      if (inside(x, y) && a[x][y] && !v[x][y]){
        T[r][c] += dfs(x,y);
      }
    }

    return T[r][c];
  };

  // id, sz
  map<int,int> mp;
  
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (a[i][j] && !v[i][j]){
        mp[id] = dfs(i, j);
        cout << i << " " << j << " " << 
        id++;
      }
    }
  }

  // Rows
  for (int i = 1; i <= n; i++){
    set<int> s;

    for (int j = 1; j <= m; j++){
      // up
      for (int k = -1; k<=1; k++){
        if (a[i + k][j]){
          s.insert(ids[i + k][j]);
        }
      }
    }

    for (auto x: s){
      R[i] += mp[x];
    }

  }

  // Cols
  for (int j = 1; j <= m; j++){
    set<int> s;
    for (int i = 1; i <= n; i++){
      for (int k = -1; k <= 1; k++){
        if (a[i][j + k]){
          s.insert(ids[i][j + k]);
        }
      }
    }
    for (auto x: s){
      C[j] += mp[x];
    }
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){

      if (a[i][j] && !vis[i][j]){
        int sz = 0;
        queue<pair<int,int>> q;
        q.push({i, j});

        int A, B, l, r;
        A = n, l = m;
        B= 1, r = 1;
        
        vis[i][j] = 1;

        while (q.size()){
          auto p = q.front();
          q.pop();
          int r= p.first, c = p.second;

          A = min(A, r);
          B = max(B, r);
          l = min(l, c);
          r = max(r, c);

          sz++;

          for (int k = 0; k < 4; k++){
            int x = r + dr[k], y = c + dc[k];
            if (inside(x, y) && a[x][y] && !vis[x][y]){
              q.push({x, y});
              vis[x][y] = 1;
            }
          }
        }

        // update
        A--; l--;
        A = max(A, 1);
        l = max(l, 1);
        B++; r++;

        // cout << A << " " << B << " " << l << " " << r << " " << sz << endl;
        p[A][l] += sz;
        p[B + 1][l] -= sz;
        p[A][r + 1] -= sz;
        p[B + 1][r + 1] += sz;

      }
    }
  }

  for (int i = 1; i <= n + 2; i++){
    for (int j = 1; j <= m + 2; j++){
      p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    }
  }

  // count dots
  vector<int> rows(n + 1), cols(m + 1);

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      rows[i] += (a[i][j] == 0);
      cols[j] += (a[i][j] == 0);
    }
  }

  int ans = 0;

  function<int(int,int,int,int)> in = [&](int A, int B, int l, int r){
    if (A > B || l > r) return 0;
    return p[B][r] - p[B][l - 1] - p[A - 1][r] + p[A - 1][l - 1];
  };

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      ans = max(ans, R[i] + C[j] - p[i][j] + rows[i]+cols[j] - (a[i][j] == 0));
    }
  }

  cout << ans  << endl;
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