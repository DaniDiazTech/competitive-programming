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
  int x1, x2, x3 = INF, x4 = -1, y1, y2, y3 = INF, y4 = -1, area = 0;
  
  for (int i = 0; i < n; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    area += (x2 -  x1) * (y2 - y1);
    x3 = min(x3, min(x1, x2));
    y3 = min(y3, min(y1, y2));
    x4 = max(x4, max(x1, x2));
    y4 = max(y4, max(y1, y2));
  }
  if (area == (x4 - x3) * (y4 - y3) && (y4 - y3) == (x4 - x3)){
    cout << "YES";
  }
  else cout << "NO";
  cout << endl;
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
