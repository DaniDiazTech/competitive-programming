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

struct segtree{
  int size;
  vii tree;

  int merge(int a, int b){
    return min(a, b);
  }
  void init(int n){
    size = 1;
    while (size < n) size *= 2; 
    tree.assign(2 * size, 0);
  }

  void build(vii &a, int x, int lx, int rx){
    if (rx - lx == 1){
      if (lx < (int)a.size()) tree[x] = a[lx];
      return;
    }
    int m = (lx + rx) /2, lc = 2 * x + 1, rc = 2 * x + 2;
    build(a, lc, lx, m);
    build(a, rc, m, rx);
    tree[x] = merge(tree[lc], tree[rc]);
  }

  void build(vii &a){
    build(a, 0, 0, size);
  }

  int mn(int l, int r, int x, int lx, int rx){
    if (lx >= l && rx <= r){
      return tree[x];
    }
    if (lx >= r || rx <= l){
      return oo;
    }
    int m = (lx + rx) / 2, lc = 2 * x + 1, rc = 2 * x + 2;
    return merge(mn(l,r, lc, lx, m),  mn(l,r,rc,m,rx));
  }

  int mn(int l, int r){
    return mn(l, r, 0, 0 , size);
  }
};

void solve(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  forn(i,n) cin >> a[i];
  segtree st;
  st.init(n);
  st.build(a);

  forn(i,q){
    int l, r; cin >> l >> r;
    cout << st.mn(--l, r) << endl;
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
