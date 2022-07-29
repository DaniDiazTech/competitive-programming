/*
Problem name: Welcome to At coder
Algorithm or Logic:
Complexity: 
Link:https://atcoder.jp/contests/practice/tasks/practice_1
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
  int a, b, c;
  cin >> a >> b >> c;

  string s;
  cin >> s;
  int su = a + b + c;
  cout << su << " " << s << endl; 
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
