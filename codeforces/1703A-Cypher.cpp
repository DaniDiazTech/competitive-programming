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
  // 0 to 9
  int n;
  cin >> n;

  // arr[i] 0 to 9
  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];
  
  for (int i = 0; i < n; i++){
    int b;
    cin >> b;
    // moves
    string s;
    cin >> s;

    int finalmoves = 0;
    for (char ch: s) finalmoves += (ch == 'U') ? -1 : 1;
    arr[i] += finalmoves;

    if (arr[i] > 9){
      arr[i] -= 10;
    }
    else if (arr[i] < 0){
      arr[i] += 10; 
    }
  }

  for (auto j: arr){
    cout << j << " ";
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
