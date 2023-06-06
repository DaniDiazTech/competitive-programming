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

  struct item{
    int seg;
    int suf;
    int pref;
    int sum;
    void init(int x){
      seg = suf = pref = sum = x;
    }
  };

  item NEUTRAL = {0,0,0,0};

  int size;
  int best;
  vector<item> t;

  int l(int x){
    return 2 * x + 1;
  }
  int r(int x){
    return 2 * x + 2;
  }
  int m(int lx, int rx){
    return (lx + rx) / 2;
  }

  void calc_best(){
    best = max(t[0].seg, (int)0);
  }

  void merge(int x){
    item left = t[l(x)], right = t[r(x)];
    item mrg;
    mrg.pref = max(left.pref, left.sum + right.pref);
    mrg.suf = max(right.suf, left.suf + right.sum);
    mrg.sum = left.sum + right.sum;
    mrg.seg = max(max(left.seg, right.seg), left.suf + right.pref);
    t[x] = mrg;
  }

  void init(int n){
    size = 1;
    while (size < n) size *= 2;
    if (n == 1) size =2;
    t.assign(2 * size, NEUTRAL);
  }

  void build(vii &a, int x, int lx, int rx){
    if (rx - lx == 1){
      if (lx < (int)a.size()){
        item it;
        it.init(a[lx]);
        t[x] = it;
      }
      return;
    }

    build(a, l(x), lx, m(lx, rx)); 
    build(a, r(x), m(lx, rx), rx); 
    merge(x);
    calc_best();
  }

  void build(vii &a){
    build(a, 0 , 0 , size);
  }

  void update(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      item it;
      it.init(v);
      t[x] = it;
      return;
    }
    if (u < m(lx, rx)){
      update(u, v, l(x), lx, m(lx, rx));
    }
    else update(u, v, r(x), m(lx, rx), rx);
    merge(x);
    calc_best();
  }

  void update(int u, int v){
    update(u, v, 0, 0, size);
  }
};


void solve(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  forn(i,n) cin >> a[i];
  stree st;
  st.init(n);
  st.build(a);
  cout << st.best << endl;
  forn(i,q){
    int u, v; cin >> u >> v;
    st.update(u, v);
    cout << st.best << endl;
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
