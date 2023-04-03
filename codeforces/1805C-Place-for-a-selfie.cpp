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
  int n, m; cin >> n >> m;
  int k[n];
  forn(i,n){
    cin >> k[i];
  }
  sort(k, k + n);
  vector<vector<int>> v;
  forn(i,m){
    int a, b, c; cin >> a >> b >> c;
    int ind = lower_bound(k, k +n, b) - k;
    // First element greater than b
    // Check such number exist
    if (ind < n && (b - k[ind]) * (b - k[ind]) < 4 * a * c){
      cout << "YES\n" << k[ind] << endl;
      continue;
    }
    ind--;
    if (ind >= 0 && (b - k[ind]) * (b - k[ind]) < 4 * a * c){
      cout << "YES\n" << k[ind] << endl;
      continue;
    }
    cout << "NO\n";
  }
  cout << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
