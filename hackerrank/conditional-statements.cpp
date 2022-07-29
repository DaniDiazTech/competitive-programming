/*
Problem name: Conditional statements
Algorithm or Logic:
Complexity: 
Link: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'

// Solution
void solve(){
  unordered_map<int, string> mp;
  mp = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6,  "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

  int x;
  cin >> x;

  if (x > 9){
    cout << "Greater than 9" << endl; 
  }
  else{
    cout << mp[x] << endl;
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
  int tc = 1;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
