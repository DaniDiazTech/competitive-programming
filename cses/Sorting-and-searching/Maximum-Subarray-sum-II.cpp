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
  int n, a, b;
  cin >> n >> a >> b;
  int pref[n + 1];
  for (int i = 1; i <= n; i++){
    int x; cin >>x;
    pref[i] = x + pref[i - 1];
  }
  // store a values
  multiset<int> s;
  int ans = -INF;
  for (int i = a; i <= n; i++){
    if (i > b) s.erase(s.find(pref[i - b- 1]));
    s.insert(pref[i  - a]);
    ans = max(ans , pref[i] - *s.begin());
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
