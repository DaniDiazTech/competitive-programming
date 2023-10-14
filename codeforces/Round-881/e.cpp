// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int MX = 1e8;

typedef vector<int> vii;
 
// Exclusive in rx
struct segtree{
  int size;
  vector<int> sums;
 
  void init(int n){
    // Increase n to the nearest power of two
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, 0);
  }
 
  // Build in linear time
  void build(vector<int> &a, int x, int lx, int rx){
    if (rx - lx  == 1){
      // Leaf
      if (lx < (int)a.size()){
        sums[x] = a[lx];
      }
      return;
    }
 
    int m = (lx + rx) / 2 ;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
  }
 
  void build(vector<int> &a){
    build(a, 0, 0, size);  
  }
 
  // Set u to v
  // x => position in the array
  // Segment lx, rx
  // The right boundary doesn't include the last element
 
  void set(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      // Leaf
      sums[x] = v;
      return;
    }
    // Decide in which subtree we're going to go
    int m = (lx + rx) / 2;
 
    if (u < m){
      // Left child
      set(u,v, 2 * x + 1, lx, m);
    }
    else{
      set(u, v, 2 * x + 2, m, rx);
    }
    // When backtracking
    sums[x] = sums[2 * x +  1] + sums[2 * x + 2];
  }
 
 
  void update(int u,int v){
    // Goes to the leaf, and back from the recursion assign values up to the root
    set(u, v, 0, 0, size);
  }
 
  // lx, rx -> Current
  // x = current index of segtree
  // sum array
  int sum(int l, int r, int x, int lx, int rx){
    // From l to r
    // Don't intersect
    if (lx >= r || l >= rx) return 0;
    if (lx >= l && rx <= r){
      // Whole segment
      return sums[x];
    }
    // If doesn't work go to both children
    int m = (lx + rx) / 2;
    return sum(l, r, 2*x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
  }
 
  int query(int l, int r){
    return sum(l, r, 0, 0, size);
  }
};

void solve(){
  int n, m;
  cin >> n >> m;

  vector<int> b(n);  
  vector<pair<int,int>> M;

  for (int i =0;i <m; i++){
    int l, r; cin>> l >> r;
    l--;r--;
    M.push_back({l,r});
  }

  int q; cin >> q;
  vector<int> Q;
  for (int i = 1; i <= q; i++){
    int l; cin >> l;
    Q.push_back(--l);
  } 
  segtree st;

  st.init(n);
  st.build(b);

  // Iterate over q
  int l = -1, r = q;
  // binary over segtree
  // process queries
  while (l + 1 < r){
    int m= (l + r) / 2;
    // update from r to m
    for (int i = max(l,0); i <= m; i++){
      st.update(Q[i], 1);
    }
    // Simulate
    bool f = 0;

    for (auto range: M){
      int sz = ((range.second - range.first + 1) / 2) + 1;
      int x = st.query(range.first, range.second + 1);

      if (x >= sz){
        // cout << "M: " << m << " x: " << x << endl;

        // cout << sz << endl;
        // cout << range.first << " " << range.second << '\n';
        f = 1;
        break;
      }

    }

    if (f){
      // remove from current l to m
      for (int i = max(l,0); i <= m; i++){
        st.update(Q[i], 0);
      }
      // cout << "L: " << l << " R: " << r << endl;
      // cout << "SCORE: " <<  x << endl;

      r = m;
    }
    else{
      l = m;
    }
  }
  cout << (r == q ? -1 : r + 1) << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
