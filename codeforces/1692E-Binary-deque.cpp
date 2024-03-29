// Binary Deque
// Accepted/ Not accepted
// https://codeforces.com/contest/1692/problem/E

#include <bits/stdc++.h>

using namespace std;

// Solution
void solve(){
  int n, s;
  cin >> n >> s;

  // Prefix sum
  int arr[n];

  cin >> arr[0];

  for (int i = 1; i < n; i++){
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
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
