// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 101;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int g[MAX][MAX];
int vis[MAX][MAX];
// L R D U
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, 1, -1};

int n, m;

bool valid(int i, int j, int ite){
  return (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] != ite);
}


void solve(){
  // Basically dijkstra
  cin >> n >> m;

  forn(i,n){
    forn(j,m){
      cin >> g[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      int ite = ((i) * m) + (j + 1);
      // (i, j) -> Cell to start with
      priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
      // Pair: {weigth of cell, i, j}
      pq.push({g[i][j], {i, j}});
      int mx = 0;
      int cnt = 0; 
      // cout << "STARTING: " << i << ", " << j << " D: " << g[i][j] << endl;
      // Neighbors are adjacent in the matrix
      while (!pq.empty()){
        pair<int, pii> p = pq.top(); 
        int d = p.ff, x = p.ss.ff, y  = p.ss.ss;
        cnt++;
        pq.pop();
        if (mx >= d){
          break;
        }
        mx = d;
        // cout << "  NODE: " << d << " " << x <<" " << y << endl;
        for (int k = 0; k < 4; k++){
          int xx = x + dirx[k], yy = y + diry[k];
          if (valid(xx, yy, ite) && mx < g[xx][yy]){
            // cout << "    Children: " << g[xx][yy] << " " << xx <<" " << yy << endl;
            vis[xx][yy] = ite;
            pq.push({g[xx][yy], {xx, yy}});
          }
        }
      }
      ans = max(cnt, ans);
    }
  }
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
