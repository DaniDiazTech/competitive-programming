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
  vector<int> sums;

  void init(int n){
    // Increase n to the nearest power of two
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, 0);
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


  void set(int u,int v){
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

  int sum(int l, int r){
    return sum(l, r, 0, 0, size);
  }
};

void solve(){
  int n, m;
  cin >> n >> m;
 // Two operations 1: get sum of range {l, r}: Set value of u to v 

  segtree st;
  st.init(n); // Initialize segment tree with an array of size n
  // Can be optimized
  for (int u = 0; u < n; u++){
    int v; cin >> v;
    st.set(u, v);
  }
   
  for (int i =0 ; i < m;i++){
    int op, x, y; cin >> op >> x >> y;
    if (op == 1){
      st.set(x, y);
    }
    if (op == 2){
      cout << st.sum(x, y) << endl;
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
