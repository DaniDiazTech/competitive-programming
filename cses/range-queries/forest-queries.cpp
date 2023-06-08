// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;
typedef vector<int> vii;

const int MAX = 1100;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

int a[MAX][MAX];
void solve(){
  int n, q;
  cin >> n >> q;
  for (int i =0 ;i < n; i++){
    for (int j = 0; j < n; j++){
      char ch; cin >> ch;
      a[i + 1][j + 1] = (int)(ch == '*') + a[i + 1][j] + a[i][j + 1] - a[i][j];
    }
  }
  auto query = [](int x1, int y1, int x2, int y2){
    return (a[y2][x2] - a[y1 - 1][x2] - a[y2][x1 - 1] + a[y1 - 1][x1 - 1]);
  };
  forn(i,q){
    int y1, x1, y2, x2;
    cin >>y1 >> x1 >> y2 >> x2;
    cout << query(x1,y1,x2,y2) << endl;
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
