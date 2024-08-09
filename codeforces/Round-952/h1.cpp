// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<bool>> vis(n, vector<bool>(m));
  for (int i =0 ;i < n; i++){
    for (int j= 0;j < m; j++){
      char ch; cin >> ch;
      a[i][j] = ch == '#';
      vis[i][j] = 0;
    }
  }

  vector<int> rows(n + 5), cols(m + 5), dotr(n + 5), dotc(m + 5);
  int A, B, C, D;

  function< int(int, int)> dfs = [&](int i, int j){
    vis[i][j] = true;  
    int sz = 1;
    A = min(A, i);
    B = max(B, i);
    C = min(C, j);
    D = max(D, j);

    for (int k = 0; k< 4; k++){
      int x = dr[k] + i, y = dc[k] + j;
      if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] && !vis[x][y]){
        sz += dfs(x, y);
      }
    }
    return sz;
  };

  for (int i =0;i < n; i++){
    for (int j = 0;j < m; j++){
      dotr[i + 1] += a[i][j] == 0;
      dotc[j + 1] += a[i][j] == 0;
      if (a[i][j] && !vis[i][j]){
        A = n + 5, C = m + 5;
        B = -1, D = -1;
        int sz = dfs(i, j);

        A--; C--;
        A = max(A, 0);
        C = max(C, 0);
        B++; D++;

        A++, B++, C++, D++;

        rows[A] += sz;
        rows[B + 1] -= sz;

        cols[C] += sz;
        cols[D + 1] -= sz;
      }
    }
  }

  int ans = 0;
  for (int i = 1;i <= n; i++){
    rows[i] += rows[i - 1];
    ans = max(ans, rows[i] + dotr[i]);
  }

  for (int i = 1; i <= m; i++){
    cols[i] += cols[i - 1];
    ans = max(ans, cols[i] + dotc[i]);
  }
  cout << ans << endl;
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
