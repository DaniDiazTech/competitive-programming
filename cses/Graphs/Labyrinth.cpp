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

int n, m, ax, ay, bx, by;
char a[MAX][MAX];
int vis[MAX][MAX];
char par[MAX][MAX];

// U D R L
char l[] = { 'U', 'D', 'R', 'L'};
map<char, pair<int, int>> d = {
  {'U', {-1, 0}},
  {'D', {1, 0}},
  {'R', {0, 1}},
  {'L', {0, -1}},
};

bool valid(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#')
    return true;
  return false;
}

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({ i, j });
  vis[i][j] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int r = x + d[l[i]].first;
      int c = y + d[l[i]].second;
      if (valid(r, c) && vis[r][c] == -1) {
        q.push({ r, c });
        vis[r][c] = vis[x][y] + 1;
        par[r][c] = l[i];
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      vis[i][j] = -1;
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        ax = i; ay = j;
      }
      if (a[i][j] == 'B') {

        bx = i; by = j;
      }
    }
  bfs(ax, ay);

  if (vis[bx][by] != -1){
    cout << "YES" << endl;
    cout << vis[bx][by] << endl;
    // Reconstruct the answer.
    string ans = "";
    int r = bx, c = by;
    while (!(r == ax && c == ay)){
      char ch =  par[r][c];
      ans +=ch;
      // The reverse
      r -= d[ch].first;
      c -= d[ch].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  else
    cout << "NO" << endl;
}

int32_t main() {
  fastInp;
#if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
