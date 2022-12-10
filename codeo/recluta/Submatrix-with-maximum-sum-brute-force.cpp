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
  int rows, columns;
  cin >> rows >> columns;
  int a[rows][columns];
  forn(i, rows){forn(j, columns) cin >> a[i][j];}
  int best = MINF;

  for (int r0 = 0; r0 < rows; r0++){
    for (int c0 = 0; c0 < columns; c0++){
      for (int r1 = r0; r1 < rows; r1++){
        for (int c1 = c0; c1 < columns; c1++){
          // Calculate sum
          int sum = 0;
          for (int i = r0; i <= r1; i++){
            for (int j = c0; j <= c1; j++){
              sum += a[i][j];
            }
          }
          best = max(best, sum);
        }
      }
    }
  }
  cout << best << endl;
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
