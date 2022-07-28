/*
Problem name: Team
Algorithm or Logic: Given 3 binary numbers return 1 if 2 or more are 1, else 0
Complexity: O(1) 
Link: https://codeforces.com/problemset/problem/231/A
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'

// Solution
int solve(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int s = a + b + c;

  return (s >= 2) ? 1: 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local. Comment out if the online judge doesn't use the flag
  #ifndef ONLINE_JUDGE
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int tc;
  cin >> tc;

  int counter = 0;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    counter += solve();
  }

  cout << counter << endl;

  return 0;
}
