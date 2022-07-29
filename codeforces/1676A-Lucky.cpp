/*
Problem name: 
Algorithm or Logic:
Complexity: 
Link:
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

  int countl, countr;
  countl = countr = 0;

  for (int i = 0; i < 3; i++){
    char j = s[i];
    int x = j - '0';
    countl += x;
  }

  for (int i = 3; i < 6; i++){
    char j = s[i];
    int r = j - '0';
    countr += r;
  }

  string ans = (countl == countr) ? "YES": "NO";

  cout << ans << endl;
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
