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
  int n, l;
  cin >> n >> l;
  vector<int> a;
  forn(i,n){
    int x; cin >> x;
    a.pb(x);
  }
  sort(a.begin(), a.end());
  // Get max gap;
  int g1, g2, gap = -1;
  // Check extremes
  double e1 = MINF, e2 = MINF;
  if (a[0] != 0){
    e1 = a[0]; 
  }
  if (a[n - 1] != l){
    e2 = l - a[n - 1];
  }

  forn(i,n - 1){
    if ((a[i + 1] - a[i]) > gap){
      gap = (a[i + 1] - a[i]);
      g1 = a[i]; g2 = a[i + 1];
    }
  }
  
  double ans = (double)(g2 - g1) / 2;
  ans = max(max(ans, e1), e2);
  cout << setprecision(9) << ans << endl; 
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
