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
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i =0 ; i < n; i++){
    for (int j = 0 ; j <  m; j++){
      cin >> a[i][j];
    }
  }

  // Select two rows
  // Compress them and create a 1D array.
  // Apply Kadane's algorithm to the 1D array.
  int best = MINF;
  for (int r= 0; r< n; r++){
    // Create 1d vector
    vector<int> sum(m, 0 );
    for (int r1 = r; r1 < n; r1++){
      for (int c = 0 ; c < m; c++)
        sum[c] += a[r1][c];
      int localbest = MINF;
      int sm = 0;
      for (int c = 0; c < m; c++){
        sm = max(sum[c], sm + sum[c]);
        localbest = max(sm, localbest);
      }
      best = max(best, localbest);
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
