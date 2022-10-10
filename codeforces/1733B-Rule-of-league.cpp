/*
Made by Daniel Diaz (Danidiaztech)
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
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
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

// int arr[MAX];

 // Solution
void solve(){
  int n, x, y;

  cin >> n >> x >> y;

  int k = max(x, y);
  if ((x != 0 && y != 0) || (k == 0)){
    cout << -1 << endl;
    return;
  }
  else if ((n - 1) % k){
    cout << -1 << endl;
    return;
  }

  int current = 0;
  for (int i = 1; i < n ; i++){
    if ((i - 1) % k == 0 ){
      current = i;
    }
    cout << current + 1<< " ";
  }
  cout << endl;
}

int32_t main() {
  fastInp;

  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
