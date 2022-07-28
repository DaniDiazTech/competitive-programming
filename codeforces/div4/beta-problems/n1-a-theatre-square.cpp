/*
Problem name: Theatre Square
Algorithm or Logic: Analyze x and y axis separately
Complexity: 
Link: https://codeforces.com/problemset/problem/1/A
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long
#define double long double

// Solution
void solve(){
  double n, m, a;
  cin >> n >> m >> a;

  int ans = ceil(n / a) * ceil(m / a);
  cout << ans << endl;
}

int32_t main() {
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
  int tc = 1;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
