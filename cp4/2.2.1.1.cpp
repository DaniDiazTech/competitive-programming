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
  // Sort vector of tuples with the foll
  vector<tuple<int, string, string>> v;
  int n; cin >> n;
  for (int i = 0 ; i < n ;i++){
    int a; string l, f; cin >>a >> l >> f;
    v.pb({a, l, f});
  }
  sort(v.begin(), v.end(), [](const auto &x, const auto &y){
    const auto [a1, l1, f1] = x;
    const auto [a2, l2, f2] = y;
    if (a1 == a2){
      if (l1 == l2){
        // Increasing order of first names
        return f1 < f2;
      }
      // Decreasing order of last names
      return l1 > l2;
    }
    return a1 < a2;
  });
  for (auto x: v){
    cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) <<  endl;
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
