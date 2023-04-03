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
  // Given a 2D array of n*n, 1 <= n <= 10^4
  // 1. Rotate 90 degrees counter clockwise
  // 2. Transpose array (switch rows and columns) 
  // 3. Mirror 2D array along x, or y axis
  int n;
  cin >> n;
  int a[n][n];
  forn(i,n)
    forn(j,n)
      cin >> a[i][j];

  cout << "Rotated array" << endl;
  forn(i,n){
    forn(j, n){
      cout << a[j][(n - 1) - i] << ' ';
    }
    cout << endl;
  }

  cout << "Transposed array" << endl;
  forn(i,n){
    forn(j, n){
      cout << a[j][i] << ' ';
    }
    cout << endl;
  }

  cout << "Mirrored array Y:" << endl;
  forn(i,n){
    forn(j, n){
      cout << a[i][(n - 1) - j] << " ";
    }
    cout << endl;
  }
  cout << "Mirrored array X:" << endl;
  forn(i,n){
    forn(j, n){
      cout << a[(n - 1) - i][j] << " ";
    }
    cout << endl;
  }

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
