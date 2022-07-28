/*
Problem name: Next round
Algorithm or Logic:
Complexity: 
Link: https://codeforces.com/problemset/problem/158/A
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
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  int m = arr[k - 1];
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (arr[i] > 0 && arr[i] >= m){
      ans++; 
    } 
    else{
      break;
    }
  }

  cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local.
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
