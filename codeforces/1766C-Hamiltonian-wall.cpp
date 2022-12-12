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

// Key is to realize you have two ways -> Start at 1st or 2nd row
// int arr[MAX];
void solve(){
  int n;
  cin >> n;
  string a[2];
  cin >> a[0];
  cin >> a[1];
  // Two ways to start
  for (int row = 0; row < 2; row++){
    bool ok = 1;
    int x = row;
    for (int i =0; i < n; i++){
      if (a[x][i] != 'B'){
        ok = 0;
      }
      // If it equals B
      if (a[!x][i] == 'B'){
        // Changes row
        x ^= 1;
      }
    }
    // once it finish iterating
    if (ok){
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
