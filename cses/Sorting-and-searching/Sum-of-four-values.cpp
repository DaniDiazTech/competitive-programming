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

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

// int arr[MAX];
void solve(){
  int n, x;
  cin >> n; cin >> x;
  vector<vector<int>> a;
  for (int i  = 1; i <= n; i++){
    int ai; cin >> ai;
    a.pb({ai, i});
  }
  sort(a.begin(), a.end());

  // Iterate over all pairs
  // Then search for the remaining value to complete x
  // Use two pointers to get the remaining value
  for (int i=0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      int sum  = a[i][0] + a[j][0];
      if (sum >= x){
        break;
      }
      // Two pointers
      int search = x - sum;
      
      for (int l = j +1, r =  n - 1; l < r;){
        int s = a[l][0] + a[r][0];
        if (s == search){
          // Process output
          cout << a[i][1] << " " <<  a[j][1] << " " << a[l][1] << " " << a[r][1];
          return;
        }

        if (s > search){
          r--;
        }
        else{
          l++;
        }
      }

    }
  }
  cout << "IMPOSSIBLE" << endl;
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
