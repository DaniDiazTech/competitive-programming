/*
Problem name: 
Algorithm or Logic:
Complexity: 
Link:
More info: Unsolved
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
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


 // Solution
void solve(){
  int n, m;
  cin >> n >> m;

  string grid[n];
  string arr[n];

  string col(m, '.'); // 9 .........

  for (int i = 0; i < n; i++) cin >> grid[i];
  
  for (int i = 0; i < n; i++) arr[i] = col;

  // 2 3
  // ***
  // o.*

  // ...
  // ...

  // *.*
  // o**

  arr[n - 1] = grid[n - 1];

  for (int i = n - 2; i >= 0; i--){
    for (int j = 0; j < m; j++){
      char ch = grid[i][j];
      if (ch == '*'){
        for (int z = i + 1; z < n; z++){
          if (arr[z][j] != '.'){
            arr[z - 1][j] = ch;
            break;
          }

          if (z + 1 == n) arr[z][j] = ch;
        }
      }
      else if (ch == 'o'){
        arr[i][j] = ch;
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
