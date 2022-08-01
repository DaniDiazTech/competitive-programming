/*
Problem name: Difference Operations
Algorithm or Logic:
Complexity: 
Link: https://codeforces.com/problemset/problem/1708/A  
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;


// Solution
void solve(){
  int n;
  cin >> n;
  
  bool y = 1;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];


  for (int i = 1; i < n; i++){
    if (arr[i] % arr[0]){
      y = 0;
      cout << "NO" << endl;
      break;
    }
  }

  if (y) cout << "YES" << endl;
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
