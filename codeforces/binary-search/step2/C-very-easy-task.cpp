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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

bool f(int t, int x, int y, int n){
  if (t < min(x, y)){
    return 0;
  }
  int ans = 1;
  t -= min(x, y);
  if (t < 0){
    return ans >= n;
  }
  ans += (t / x) + (t / y);
  return ans >= n;
}
void solve(){
  int n, x, y;
  cin >> n >> x >> y;

  int l = 0, r = 1e12 + 1000;
  while (l+ 1 < r){
    int m = (l + r) / 2;
    if (f(m, x, y, n)){
      r = m;
    }
    else l = m;
  }
  cout << r << endl;
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
