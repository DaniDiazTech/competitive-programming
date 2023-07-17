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

vector<int> v;
int n, k;
bool f(double x){
  int cnt = 0;
  for (auto num: v){
    cnt += floor(num / x);
  }
  return k <= cnt;
}
void solve(){
  cin >> n >> k;
  forn(i,n){
    int x; cin >> x;
    v.pb(x);
  }
  // With 100 ops is enough for precision
  // L is never evaluated in the function as 0;
  double l = 0,  r = 1e8; 
  for (int i = 0 ; i < 100; i++){
    double m = (l + r) / 2;
    if (f(m)){
      l = m;
    }
    else r = m;
  }
  cout << setprecision(7) <<  l << endl;
  
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
