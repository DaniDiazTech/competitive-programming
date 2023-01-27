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

  // Gets 2d array
  int n = 20;
  int step = 4; 
  int a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
     cin >> a[i][j];
  int ans = 0; 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      // Horizontal
      if (j + step < n){
        int hor = 1;
        for (int h = j; h < j + step; h++){
          hor *= a[i][h];
        }
        ans = max(hor, ans);
      }
      // Down
      if (i + step < n){
        int down = 1;
        for (int d = i; d < i + step; d++){
          down *= a[d][j];
        }
        ans = max(down, ans);
      }
      // Diagonal down
      if (i + step < n && j + step < n){
        int dig  = 1;
        for (int k = i,l = j; k < i + step && l < j + step; k++, l++){
          dig *= a[k][l]; 
        }
        ans = max(dig, ans);
      }
      // Diagonal up
      if (i - step >= 0 && j + step < n){
        int dig2 = 1;
        for (int k = i, l = j; k > i - step && l < j + step; k--, l++){
          dig2 *= a[k][l];
        }
        ans = max(dig2, ans);
      }
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
