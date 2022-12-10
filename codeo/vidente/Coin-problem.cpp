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

const int MAX = 1e5;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

// Up to limit 10000
int dp[MAX + 10];
int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  int a[n];
  for (int i =0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  dp[0] = 1;
  for (int i = 0; i < n ;i++){
    for (int j= 1; j <= MAX + 1; j++){
        if (j - a[i] >=  0)
          dp[j] = (dp[j] +  dp[j - a[i]]) % MOD;
    }
  }
  int q; cin >> q;
  while(q--){
    int c; cin >> c;
    cout << dp[c] << endl;
  }
}
