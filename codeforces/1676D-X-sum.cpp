/*
Problem name: 
Algorithm or Logic:
Complexity: 
Link:
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Definitions
#define endl '\n'
#define int long long int
#define double long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN

// Templates

// Solution
void solve(){
  int n, m;
  cin >> n >> m;
  int arr[n][m];

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }


  int mx = 0;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      // Try every possible sum
      int s = arr[i][j];

      // Upper left
      for (int row = i - 1, column = j - 1; row < MAX; row--, column--){
        if (row < 0 || row > (n - 1) || column < 0 || column > (m - 1)) break;
        s += arr[row][column];
      }

      // Upper right
      for (int row = i- 1, column = j + 1; row < MAX; row--, column++){
        if (row < 0 || row > (n - 1) || column < 0 || column > (m - 1)) break;
        s += arr[row][column];
      }
      
      // Bottom left
      for (int row = i + 1, column = j - 1; row < MAX; row++, column--){
        if (row < 0 || row > (n - 1) || column < 0 || column > (m - 1)) break;
        s += arr[row][column];
      }

      // Bottom right
      for (int row = i + 1, column = j + 1; row < MAX; row++, column++){
        if (row < 0 || row > (n - 1) || column < 0 || column > (m - 1)) break;
        s += arr[row][column];
      }

      if (s > mx){
        mx = s;
      }
    }
  }

  cout << mx << endl;
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
