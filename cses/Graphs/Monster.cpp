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

const int MAX = 1010;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int n,m;
char g[MAX][MAX];
// Distance from monsters
int dism[MAX][MAX]; 
// Distance from A
int disa[MAX][MAX]; 


char dir[] = {'L', 'R', 'U', 'D'};
char rev[] = {'R', 'L', 'D', 'U'};
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
map<char,int> mp = {{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};

bool is_valid(int x, int y){
  if ((x >= 0 && x < n) && (y >= 0 && y < m) && (g[x][y] != '#') )
    return true;
  return false;
}

bool is_exit(int x, int y){
  if (is_valid(x,y) && ( x == 0 || x == n - 1 ||  y == 0 || y == m - 1) && (g[x][y] == '.' || g[x][y] == 'A'))
    return true;
  return false;
}

void solve(){
  // Another approach: Start with distance from Monsters
  cin >> n >> m;
  queue<pii> mo, a;
  map<pii, pair<pii, char>> path;
  int sx, sy, ex = -1, ey  =-1;
  forn(i,n){
    forn(j, m){
      cin >> g[i][j];
      dism[i][j] = INF;
      if (g[i][j] == 'M'){
        mo.push({i, j});
        dism[i][j] = 0;
      }
      else if (g[i][j] == 'A'){
        if (is_exit(i, j)){
          cout << "YES\n0" << endl;
          return;
        }
        a.push({i,j});
        sx = i; sy = j;
      }
    } 
  }

  // BFS on monsters
  while (!mo.empty() ){
    pii u = mo.front(); 
    mo.pop();
    for (int i =0 ; i < 4; i++){
      int x = u.ff + dirx[i], y = u.ss + diry[i];
      if (is_valid(x, y) && dism[x][y] == INF){
        dism[x][y] = dism[u.ff][u.ss] + 1;
        mo.push({x, y});
      }
    }
  }

  // BFS on player
  while (!a.empty()){
    if (ex != -1) break;
    pii u = a.front();
    a.pop();
    for (int i = 0; i < 4; i++){
      int x = u.ff + dirx[i], y = u.ss + diry[i];
      if (is_valid(x, y) && disa[x][y] == 0){
        disa[x][y] = disa[u.ff][u.ss] + 1;
        path[{x, y}] = {{u.ff, u.ss}, dir[i]};
        if (dism[x][y] <= disa[x][y]){
          continue;
        }
        if (is_exit(x, y)){
          ex = x; ey = y;
          break;
        }
        a.push({x, y});
      }
    }
  } 

  if (ex == -1){
    cout << "NO" << endl; return;
  }
  vector<char> v;
  // Reconstruct path
  while (ex != sx || ey != sy){
    v.pb(path[{ex, ey}].ss);
    pii u = path[{ex,ey}].ff;
    ex = u.ff;
    ey = u.ss;
  }
  reverse(v.begin(), v.end());
  cout << "YES\n" << v.size() << endl;
  for (auto x: v) cout << x ;
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
