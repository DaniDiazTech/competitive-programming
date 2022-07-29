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
#define MAX LLONG_MAX
#define MIN LLONG_MIN

// Solution
void solve(){
  int n, m;
  cin >> n >> m;
  string arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  int mn  = MAX;

  for (int i = 0; i < n; i++){
    for (int j = (i + 1); j < n; j++){
      if (j > (n - 1)) break;
      int difference = 0;

      for (int in = 0; in < m; in++){
        int x =  arr[i][in] - arr[j][in];
        x = abs(x);

        difference += x;
      }

      if (difference < mn){
        mn = difference;
      }
    }
  }

  cout << mn << endl;
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
