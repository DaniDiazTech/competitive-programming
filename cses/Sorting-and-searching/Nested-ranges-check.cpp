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
  int n;
  cin >> n;
  vector<vector<int>> a;
  forn(i, n){
    int x, y; cin >> x >> y;
    a.pb({x, y, i});
  }

  vector<int> ans(n);
  vector<int> ans2(n);

  // Sort by the first element
  // In case of tie, sort by the second element
  // Descending
  sort(a.begin(), a.end(), 
  [](vector<int> &x, vector<int> &y){
    return ((x[0] < y[0]) || (x[0] == y[0] && x[1] > y[1]));
  });

  // for (auto x: a){
  //   for (auto s: x){
  //     cout << s << " ";
  //   }
  //   cout << endl;
  // }

  int mx= 0;
  // Ans 1
  // Contains
  int mn = INF;
  for (int i = n - 1; i >= 0; i--){
    if (mn <= a[i][1]){
      ans[a[i][2]]++;
    }
    mn = min(mn, a[i][1]);
  }
  
  // Ans 2
  // Contained
  for (int i = 0; i < n;i++){
    if (mx >= a[i][1]){
      ans2[a[i][2]]++;
    }
    mx = max(mx, a[i][1]);
  }


  for (auto x: ans){
    cout << x << " ";
  }
  cout << endl;
  for (auto x: ans2){
    cout << x << " ";
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
