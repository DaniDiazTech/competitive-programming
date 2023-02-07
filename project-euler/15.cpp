// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
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

int factorial(int n){
  int ans = 1;
  for (int i = 1; i <= n ; i++){
    ans *= i;
  }
  return ans;
}

void solve(){
  auto start = chrono::system_clock::now();
  // DP solution
  int n = 21;
  int a[n + 1][n + 1];
  for (int i = 0; i <= n; i++){
    a[i][0] = 1;
  }
  for (int i = 0; i <= n; i++){
    a[0][i] = 1;
  }
  for (int i = 1; i < n; i++){
    for (int j = 1; j < n; j++){
      a[i][j] = a[i - 1][j] + a[i][j - 1];
    }
  }

  cout << "RESULT: " << a[20][20] << endl;
  auto end = chrono::system_clock::now();
  cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;

  start = chrono::system_clock::now();
  // Combinatorics
  double ans = 1;
  n = 20;
  // Have to use double
  for (int i = 1; i <= n; i++){
    ans *= double(double(n + i) / double(i));
  }
  cout << "Combinatorial formula: " << (int)ceil(ans) << endl;
  end = chrono::system_clock::now();
  cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
  // Can't use factorial: Doesn't fit in long long
  cout << "Factorial comb: " << (factorial(2 * n) / (factorial(n) * factorial(n))) << endl;
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
