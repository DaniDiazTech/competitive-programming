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


bool is_valid(int row, int column, int queens[]){
  // Small modification of the N-queens problem
  bool ok = true;
  // Checks all the columns we have, from 0 to row (The rows we've declared)
  for (int r = 0;  r < row; r++){
    // Check difference in col and diagonal
    if (column != queens[r] && abs(r - row) != abs(queens[r] - column)){
      continue;
    }
    else{
      ok = false;
      break;
    }
  }
  return ok;
}

vector<vector<int>> solutions;
int search(int row, int queens[], int n){
  if (row  == n){
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(queens[i]); 
    solutions.push_back(v);
    return 1;
  }
  else{
    int total_sums = 0;
    for (int col = 0; col < n; col++){
      // Check if it's valid
      if (is_valid(row, col, queens)){
        queens[row] = col;
      
        total_sums += search(row + 1, queens, n);
      }
    }
    return total_sums;
  }
}

// int arr[MAX];
void solve(){
  string s;
  int row = 0;
  vector<vector<int>> reserved;
  while (cin >> s){
    for (int i = 0; i < 8; i++){
      if (s[i] == '*') reserved.pb({row, i});
    } 
    row++;
  }
  // for (auto x: reserved) cout << x[0] << " " << x[1] << endl;
  int n = 8;
  int queens[n];
  int total = search(0, queens, n);
  int cnt = 0;
  for (auto x: solutions){
    bool ok = true;
    for (int i = 0; i < (int)x.size(); i++){
      if (!ok) continue;
      for (auto re: reserved){
        if (i == re[0] && x[i] == re[1]){
          cnt++;
          ok = false;
          break;
        }
      }
    }
  }
  cout << total - cnt << endl;
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
