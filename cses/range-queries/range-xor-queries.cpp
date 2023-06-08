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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

struct stree{
  int size;
  vii t;
  int NEUTRAL = 0;

  int lc(int x){return 2 *x +1;}
  int rc(int x){return 2 *x +2;}

  int merge(int x, int y){
    return x ^ y;
  }

  void merge(int x){
    t[x] = merge(t[lc(x)], t[rc(x)]);
  }

  void init(int n){
    size = 1;
    while (size < n) size *= 2;
    if (n==1) size = 2;
    
    t.assign(2 * size, 0);
  }
  void build(vii &a, int x, int lx, int rx){
    if (rx - lx == 1){
      if (lx < a.size()){
        t[x] = a[lx];
      }
      return;
    }
    int m= (lx + rx) / 2 ;
    build(a, lc(x), lx, m);
    build(a, rc(x), m, rx);
    merge(x);
  }

  void build(vii &a){
    build(a, 0,0,size);
  }
  int query(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l) return NEUTRAL;
    if (lx >= l && rx <= r) return t[x];
    int m = (lx + rx) / 2;
    return query(l, r, lc(x), lx, m) ^ query(l,r, rc(x), m, rx);
  }

  int query(int l, int r){
    return query(l,r,0,0,size);
  }
};

void solve(){
  int n, q;
  cin >> n >> q;
  vii a(n);
  forn(i,n) cin >> a[i];
  stree st;
  st.init(n);
  st.build(a);
  forn(i,q){
    int l, r;
    cin >> l >> r;
    cout << st.query(l - 1, r) << endl;
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
