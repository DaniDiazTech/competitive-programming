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
  vector<int> tree;
  void init(int n){
    size = 1;
    while (size < n) size *= 2;
    // Store the minimum, so it should start with a big value
    tree.assign(2 * size, oo);
  }

  void build(vii &a, int x, int lx, int rx){
    // Leaf
    if (rx - lx == 1){
      if ((int)a.size() > lx){
        tree[x] = a[lx];
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
  }
  void build(vii &a){
    build(a, 0, 0, size);
  }

  void set(int u, int v, int x, int lx, int rx){

    if (rx - lx == 1){
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (u < m){
      // Go for left child
      set(u, v, 2 * x + 1, lx, m);
    }
    else set(u, v, 2 * x + 2, m, rx);
    tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
  }

  void set(int u, int v){
    set(u, v, 0, 0, size);
  } 

  int find_min(int l, int r, int x, int lx, int rx){
    // cout << "CURRENT MIN: " << lx << " " << rx << ": " << tree[x] << endl;
    if (lx >= l && rx <= r) return tree[x];
    if (lx >= r || rx <= l) return oo;
    int m = (lx + rx) / 2;
    return min(find_min(l, r, 2 * x + 1, lx, m), find_min(l,r, 2 * x + 2, m, rx));
  }
  
  int find_min(int l, int r){
    return find_min(l, r, 0, 0, size);
  }

};



void solve(){
  int n, m;
  cin >> n >> m;
  vii a(n);
  for (int i =0 ; i < n; i++){
    cin >> a[i];
  }
  segtree st;
  st.init(n);
  st.build(a);
  for (int i = 0; i < m; i++){
    int op, x, y; 
    cin >> op >> x >> y;
    if ( op == 1){
      st.set(x, y);
    }
    else{
      cout << st.find_min(x, y) << endl;
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
