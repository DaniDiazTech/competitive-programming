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
  int a[n + 1][m + 1];
  // Fill borders with 0
  for (int i = 0 ; i <= n; i++){
    a[i][0] = 0;
  }
  for (int j = 0; j <= m; j++){
    a[0][j] = 0;
  }
  
  for (int i =1 ; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> a[i][j];
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
    }
  }

  int best = MINF;
  for (int r = 1; r <= n; r++){
    for (int c = 1; c <= m; c++){
      for (int r1 = r; r1 <= n; r1++){
        for (int c1 = c; c1 <= m; c1++){
          // Area of the square (r, c), (r1, c1)
          best = max(a[r1][c1] - a[r1][c - 1] - a[r - 1][c1] + a[r - 1][c - 1], best);
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
