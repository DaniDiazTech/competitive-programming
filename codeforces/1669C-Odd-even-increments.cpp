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
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 51;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int arr[MAX];

 // Solution
void solve(){
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) cin >> arr[i];

  int oddind = arr[1] % 2;
  int evenind = arr[2] % 2;
  
  int ok = true;


  for (int i = 1; i <= n; i += 2){
    // cout << arr[i] << " ";
    if ((arr[i] % 2) != oddind){
      ok = false;
      break;
    }
  }

  // cout << endl;
  if (ok){
    for (int i = 2; i <= n; i += 2){
      // cout << arr[i] << " ";
      if ((arr[i] % 2) != evenind){
        ok = false;
        break;
      }
    }
  }

  string ans = (ok) ? "YES" : "NO";

  cout << ans << endl;
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
