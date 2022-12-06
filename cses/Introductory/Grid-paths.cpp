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

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

<<<<<<< HEAD
bool Grid[10][10];

vector<int> decision;
// L R U D
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
=======
bool vis[9][9];

// L R U D
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

const int max_index = 48;
int direction[max_index];


int trypath(int i, int row, int col){

  // Optimization
  // If we touch a wall, and the adjacent two sides are not visited,
  // we hit a dead end
  
  if ((vis[row][col + 1] && vis[row][col - 1]) && (!vis[row + 1][col] && !vis[row - 1][col])){
    return 0;
  }
  if ((vis[row - 1][col] && vis[row + 1][col]) && (!vis[row][col - 1] && !vis[row][col + 1])){
    return 0;
  }

  // Valid path
  if (row == 7 && col == 1) return (i == max_index);
  if (i == max_index) return 0;

  int paths = 0;
  vis[row][col] = 1;

  
  if (direction[i] != -1){
    if (!(vis[row + dr[direction[i]]][col + dc[direction[i]]]))
      paths += trypath(i + 1, row + dr[direction[i]], col + dc[direction[i]]);
  }
  else{
    for (int move = 0; move < 4; move++){
      // Make a move
      if (vis[row + dr[move]][col + dc[move]]) continue;
      paths += trypath(i + 1, row + dr[move], col + dc[move]);
    }
  }
  vis[row][col] = 0;
  
  return paths;
}

>>>>>>> 4422a1058de444916fab1aeadec0974e5dede3da

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

<<<<<<< HEAD
  string s; cin >> s;

  for (int i = 0; i < s.size(); i++){
    ik
  } 
=======
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++){
    if (s[i] == 'L') direction[i] = 0;
    else if (s[i] == 'R') direction[i] = 1;
    else if (s[i] == 'U') direction[i] = 2;
    else if (s[i] == 'D') direction[i] = 3;
    else direction[i] = -1;
  }

  // Borders
  for (int i = 0; i < 9; i++){
    vis[0][i] = true;
    vis[8][i] = true;
    vis[i][0] = true;
    vis[i][8] = true;
  }

  for (int i = 1; i <= 7; i++){
    for (int j = 1; j <= 7; j++){
      vis[i][j] = false;
    }
  }

  cout << trypath(0,1,1) << endl;
>>>>>>> 4422a1058de444916fab1aeadec0974e5dede3da
  return 0;
}
