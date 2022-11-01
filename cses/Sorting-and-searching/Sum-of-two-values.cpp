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
  int n,x;
  cin >> n >> x;
  vector<pii> v;

  for (int i = 1; i <= n; i++){
    int x; cin >> x;
    v.pb({x, i});
  }
  sort(v.begin(), v.end());
  // for (auto x: v) cout << x.first << ' ' << x.second << '|';
  // cout << endl;
  for (int i = 0; i < n; i++){
    int value = v[i].first;
    int search = x - value;
    // Binary search
    int l = i + 1, h = n - 1;
    while (l <= h){
      int mid  = (l + h)  >> 1;
      if (v[mid].first == search && mid != i){
        cout <<  v[i].second << " " << v[mid].second;
        return;
      }
      if (v[mid].first > search){
        h = mid - 1;
      }
      else l = mid + 1;
    }

  }
  cout << "IMPOSSIBLE" << endl;
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
