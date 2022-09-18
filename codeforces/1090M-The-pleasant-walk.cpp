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
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
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
  int n,k, prev = -1, c = 1,ans = 0;

  cin >> n >> k;

  int x;
  for (int i = 0; i < n; i++){
    cin >> x;

    if (prev == -1){
      prev = x;
      continue;
    }
    if (x == prev){
      ans = max(ans, c);
      c = 0;
    }
    c++;
    prev = x;
  }

  ans = max(ans, c);

  cout << ans << endl;
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
