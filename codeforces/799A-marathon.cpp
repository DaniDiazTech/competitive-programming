// A. Marathon
// Accepted
// https://codeforces.com/contest/1692/problem/A

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
    int a;
    int counter = 0;
    cin >> a;
    for (int j = 0; j < 3; j++){
      int x;
      cin >> x;
      if (x > a) counter++;
    }
    cout << counter << endl;
  }
 
  return 0;
}
