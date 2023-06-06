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
  };

  int NEUTRAL = 0;

  int size;
  vector<int> t;

  int l(int x){
    return 2 * x + 1;
  }
  int r(int x){
    return 2 * x + 2;
  }
  int m(int lx, int rx){
    return (lx + rx) / 2;
  }


  void merge(int x){
    t[x] = t[l(x)] + t[r(x)];
  }

  void init(int n){
    size = 1;
    while (size < n) size *= 2;
    if (n == 1) size = 2;
    t.assign(2 * size, NEUTRAL);
  }

  void build(vii &a, int x, int lx, int rx){
    if (rx - lx == 1){
      if (lx < (int)a.size()){
        t[x] = a[lx];
      }
      return;
    }

    build(a, l(x), lx, m(lx, rx)); 
    build(a, r(x), m(lx, rx), rx); 
    merge(x);
  }

  void build(vii &a){
    build(a, 0 , 0 , size);
  }

  void update(int u, int x, int lx, int rx){
    if (rx - lx == 1){
      t[x] = !t[x];
      return;
    }
    if (u < m(lx, rx)){
      update(u,l(x), lx, m(lx, rx));
    }
    else update(u, r(x), m(lx, rx), rx);
    merge(x);
  }

  void update(int k){
    update(k,0, 0, size);
  }

  int query(int k, int x){
    // cout << k << " " << x << " " << size <<  endl;
    if (k == 0 && x >= (size - 1)){
      // cout << "HERE" << endl;
      return x - (size -1);
    }
    if (t[l(x)] > k){
      return query(k, l(x));
    }
    else{
      return query(k - t[l(x)], r(x));
    }
  }

  int query(int k){
    // Find the kth element
    return query(k, 0);
  }
};

// int arr[MAX];
void solve(){
  int n, q;
  cin >> n >> q;
  vii a(n);
  forn(i,n) cin >> a[i];
  stree st;
  st.init(n);
  st.build(a);
  forn(i, q){
    int op; cin >> op;
    int k; cin >> k;
    if (op == 1){
      st.update(k);
    }
    else{
      cout << st.query(k) << endl;
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
