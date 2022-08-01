/*
Problem name: 
Algorithm or Logic:
Complexity: 
Link: https://codeforces.com/problemset/problem/1711/A
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long int
#define double long double
#define PB push_back

const int MAX = 10e5+ 1;
const int MIN = 0;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;


// Solution
void solve(){
  int n;
  cin >> n;

  cout << n << " ";
  
  for (int i = 1; i < n; i++){
    cout << i << " ";
  }

  cout << endl;
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
