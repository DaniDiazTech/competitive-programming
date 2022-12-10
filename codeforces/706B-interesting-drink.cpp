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


int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  vector<int> a(n);
  forn(i,n) cin >> a[i];
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  while(q--){
    int m; cin >> m;
    int l = 0, r = n -1;

    // Upper bound
    while (l <= r){
      int mid = (l + r) /2;
      if (a[mid] <= m){
        l = mid + 1;
      }
      else r = mid - 1;
    }
    cout << l << endl;
  }
  return 0;
}
