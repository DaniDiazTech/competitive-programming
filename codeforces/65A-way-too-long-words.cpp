/*
Problem name: Way too long words
Algorithm or Logic: If len of the work > 10, print the first ch, the len - 2, and last ch
Complexity: O(1)
Link: https://codeforces.com/problemset/problem/71/A
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'

// Solution
void solve(){
  string word;
  cin >> word;
  int len = word.size();
  
  if (len > 10){
    string ans = word[0] + to_string(len - 2) + word[len - 1];
    cout << ans << endl;
  }
  else {
   cout << word << endl; 
  }
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

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
