// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 2 * 1e5 +10;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int a[MAX];

// int arr[MAX];
void solve(){
  int n, t;
  cin >> n >> t;
  forn(i,n) cin >> a[i];
  // Up to 10E18 in worst case
  // 1 1e9
  // 1e9
  int l = 1, r  = 1e18;
  int ans = 0; 
  // Binary search
  while (l <= r){
    int mid = (l + r) / 2; 
    int sum = 0;
    for (int i = 0; i < n; i++){
      // Summatory
      sum += (mid / a[i]);
      if (sum >= t){
        // Avoids innecessary addition
        break;
      }
    }

    // cout << mid << endl;
    if (sum >=  t){
      // Here the answer is valid
      // But we want the minimal viable answer
      // Thus keep iterating
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
