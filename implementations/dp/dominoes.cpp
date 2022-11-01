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


int dominoes(int n){
  // Calculate number of way to place dominoes of 2 * 1 size
  // In  a n * 2 board
  if (n == 0 || n == 1){
    return 1;
  }
  // Module the number  
  return ((dominoes(n - 1) % MOD ) + (dominoes(n - 2) % MOD)) % MOD;
}


// int arr[MAX];

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
    // Never returns
    int  n = 200;
    cout << dominoes(n) << endl;
  }
  return 0;
}
