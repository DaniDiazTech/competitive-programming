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
  vector<pii> tree;

  void init(int n){
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, {oo, 0});
  }

  void build (vii &a, int x, int lx, int rx){
    if (rx - lx == 1){
      // Leaf
      if (lx < (int)a.size()){
        tree[x] = {a[lx] ,1};
      }
      return;
    }

    int m = (lx + rx) /2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    int lc = 2 * x +1, rc = 2 * x + 2;
    if (tree[lc].ff < tree[rc].ff){
      tree[x] = {tree[lc].ff, tree[lc].ss};
    }
    else if (tree[lc].ff > tree[rc].ff){
      tree[x] = {tree[rc].ff, tree[rc].ss};
    }
    else{
      tree[x] = {tree[lc].ff, tree[lc].ss + tree[rc].ss};
    }
  }

  void build(vii &a){
    build(a, 0, 0, size);
  }

  void set(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      tree[x] = {v, 1};
      return;
    }
    int m = (lx + rx) / 2;
    int lc = 2 * x +1, rc = 2 * x + 2;
    if (u < m){
      set(u,v,lc, lx, m);
    }
    else{
      set(u,v,rc, m, rx);
    }

    if (tree[lc].ff < tree[rc].ff){
      tree[x] = {tree[lc].ff, tree[lc].ss};
    }
    else if (tree[lc].ff > tree[rc].ff){
      tree[x] = {tree[rc].ff, tree[rc].ss};
    }
    else{
      tree[x] = {tree[lc].ff, tree[lc].ss + tree[rc].ss};
    }

  }
  
  void set(int u, int v){
    set(u,v, 0, 0, size);
  }

  pii min_count(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l){
      return {oo, 0};
    }
    if (lx >= l && rx <= r){
      return tree[x];
    }
    int m = (lx + rx) /2 ;
    int lc = 2 * x +1, rc = 2 * x + 2;

    pii p1 = min_count(l,r, lc, lx, m), p2 = min_count(l,r, rc, m, rx);
    if (p1.ff == p2.ff){
      return {p1.ff, p2.ss + p1.ss};
    }
    else if (p1.ff < p2.ff){
      return p1;
    }
    else return p2;
  }

  pii min_count(int l, int r){
    return min_count(l, r, 0, 0, size);
  }
};

void solve(){
  int n, m;
  cin >> n >> m;
  vii a(n);
  for (int i =0 ; i < n; i++) cin >> a[i];
  
  segtree st;
  st.init(n);
  st.build(a);

  for (int i = 0; i < m;i++){
    int op, x,y;
    cin >> op >> x >> y;
    if (op == 1){
      st.set(x,y);
    }
    else{
      pii p = st.min_count(x,y);
      cout << p.ff << " " << p.ss << endl;
    }
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
