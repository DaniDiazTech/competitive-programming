// C. Where's the bishop
// Accepted
// https://codeforces.com/contest/1692/problem/C
#include <bits/stdc++.h>

using namespace std;

int main() {

  // Only local. Comment out if the online judge doesn't use the flag
  #ifndef ONLINE_JUDGE
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  int t;
  cin >> t;

  for (int i = 0; i < t; i++){
    // Gets input
    string arr[8];
    for (int j = 0; j < 8; j++) cin >> arr[j];

    bool finished = false;

    // rows
    for (int row = 1; row < 7; row++){
      // Columns
      for (int column = 1; column < 7; column++){
        char ch = arr[row][column];
        if (ch == '#'){
          char ul = arr[row -1][column - 1];
          char ur = arr[row - 1][column + 1];
          char bl = arr[row + 1][column - 1];
          char br = arr[row + 1][column + 1];
          if (ul == '#' && ur == '#' && bl == '#' && br == '#'){
            finished = true;
            cout << row + 1 << ' ' << column + 1 << endl;
          }
        }
      }
      if (finished) break;
    }
  }

  return 0;
}
