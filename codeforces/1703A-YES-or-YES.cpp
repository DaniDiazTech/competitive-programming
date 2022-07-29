/*
Problem name: YES or YES
Algorithm or Logic:
Complexity: 
Link: https://codeforces.com/contest/1703/problem/A
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long int
#define double long double

// Solution
void solve(){
  string s;
  cin >> s; 
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  cout << ((s == "YES") ? "YES" : "NO") << endl;
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
