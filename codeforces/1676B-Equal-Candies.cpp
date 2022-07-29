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
// #define int long long int
#define double long double

// Solution
void solve(){
  int n;
  cin >> n;

  vector<int> arr;
  int count = 0;

  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int m = *min_element(arr.begin(), arr.end());

  for (int i = 0; i < n; i++){
    count += arr[i] - m;
  }
  cout << count << endl;
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
