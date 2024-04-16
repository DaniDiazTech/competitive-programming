// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


const int N = 3e5;
int n, M;

struct segtree{
  int size;
  vector<int> sums;
 
  void init(int n){
    // Increase n to the nearest power of two
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, 1);
  }
 
  // Build in linear time
  void build(vector<int> &a, int x, int lx, int rx){
    if (rx - lx  == 1){
      // Leaf
      if (lx < (int)a.size()){
        sums[x] = (a[lx]) % M;
      }
      return;
    }
 
    int m = (lx + rx) / 2 ;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    sums[x] = (sums[2 * x + 1] * sums[2 * x + 2]) % M;
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
    sums[x] = sums[2 * x +  1] * sums[2 * x + 2];
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
    if (lx >= r || l >= rx) return 1;
    if (lx >= l && rx <= r){
      // Whole segment
      return sums[x] % M;
    }
    // If doesn't work go to both children
    int m = (lx + rx) / 2;
    return (sum(l, r, 2*x + 1, lx, m) * sum(l, r, 2 * x + 2, m, rx)) % M;
  }
 
  int sum(int l, int r){
    return sum(l, r, 0, 0, size);
  }
};
 


void solve(){
  cin >> n >> M;

  segtree st;
  vector<int> a(n);
  for (int i =0 ; i < n; i++){
    cin >> a[i];
  }

  st.init(n);
  st.build(a);
  int l = 0, r= n - 1;
  string s; cin >> s;


  for (int i = 0 ;i < n; i++){
    cout << (st.sum(l, r + 1)) << ' ';
    if (s[i] == 'L') l++;
    else r--;
  }
  cout << '\n';


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
