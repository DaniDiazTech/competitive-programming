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
  int q;
  cin >> q;
  int ans = 0;
  vector<vector<int>> v;
  forn(i,q){
    int a, b, c;
    cin >> a >> b >> c;
    v.pb({a - 1,b - 1,c - 1});
  }
  
  vector<int> pebbles(3);
  for (int i = 0; i < 3; i++){
    pebbles[i] = 1;
    int s = 0;
    for (int j  = 0; j < (int)v.size(); j++){
      swap(pebbles[v[j][0]], pebbles[v[j][1]]);
      s += (pebbles[v[j][2]]);
    }
    ans = max(s, ans);
    pebbles[0] = pebbles[1] = pebbles[2] = 0;
  }
  cout << ans << endl;
}

int32_t main() {
  fastInp;

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
