/*
Problem name: 
Algorithm or Logic:
Complexity: 
Link:
More info: Unsolved
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long int
#define double long double
#define ff first
#define ss second
#define pb push_back

const int MAX = 1e6;
const int MIN = 0;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;


// Solution
void solve(){
  int n;
  cin >> n;

  vector<pair<int, int>> arr;

  for (int i = 1; i <= n; i++){
    int x;
    cin >> x;
    if (i > x){
      arr.pb(make_pair(x, i));
    }
  }

  int count = 0;

  int size = arr.size();

  

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
