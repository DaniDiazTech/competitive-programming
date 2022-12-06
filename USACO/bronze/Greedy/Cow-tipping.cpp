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

const int MAX = 12;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int board[MAX][MAX];

void flip_board(int row, int col){
  // Flip until the row and column specified
  for (int i = 0; i <= row; i++){
    for (int j = 0; j <= col; j++){
      board[i][j] = !board[i][j];
    }
  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #else
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
  #endif

  int n; cin >> n;
  forn(i,n){
    string s; cin >> s; 
    forn(j,n){
      board[i][j] = s[j] - '0';
    }
  }
  int cnt = 0;
  // Iterate from n, n up to 0, 0
  for (int i = n - 1; i >= 0; i--){
    for (int j = n -1; j >= 0; j--){
      if (board[i][j] == 1){
        flip_board(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
