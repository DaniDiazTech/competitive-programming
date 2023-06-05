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
  int letter;
  vector<int> t;
  int merge(int x){
    return (t[2 * x + 1] || t[2 * x + 2]);
  }
  void init(int n, int ch){
    letter =ch;
    size = 1;
    while (size < n){
      size *= 2;
    }
    t.assign(2 * size, 0);
  }
  void build(string &a, int x, int lx, int rx){
    if (rx - lx == 1){
      if (lx < a.size()){
        t[x] = ((a[lx] - 'a') == letter);
      }
      return;
    }
    int m = (lx + rx) / 2, lc = 2 * x + 1, rc = 2 * x + 2; 
    build(a, lc, lx, m);
    build(a, rc, m, rx);
    t[x] = merge(x);
  }
  void build(string &a){
    build(a, 0, 0, size);
  }
  void update(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      t[x] = (v == letter);
      return;
    }
    int m = (lx + rx) / 2, lc = 2 * x + 1, rc = 2 * x + 2; 
    if (u < m){
      update(u, v, lc, lx, m);
    }
    else update(u, v, rc, m, rx);

    t[x] = t[lc] || t[rc];
  }
  void update(int u, int v) {
   update(u, v, 0, 0, size); 
  }

  int query(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l){
      return 0;
    }
    if (lx >= l && rx <= r){
      return t[x];
    }
    int m = (lx + rx) / 2, lc = 2 * x + 1, rc = 2 * x + 2; 
    return (query(l, r, lc, lx, m) || query(l,r, rc, m, rx));
  }

  int query(int l, int r){
    return query(l, r,0, 0, size);
  }
};

void solve(){
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<stree> v; 
  for (int i=0 ; i < 26; i++){
    stree st;
    st.init(s.size(), i);
    st.build(s);
    v.pb(st);
  }

  forn(i,n){
    int op; cin >> op;
    if (op == 1){
      int u; char ch;
      cin >> u >> ch;
      int uu = ch - 'a';
      // Update 26 segment trees
      for (int i =0; i < 26; i++){
        v[i].update(u - 1, uu);
      }
    }
    else{
      int l, r; cin >> l >> r;
      int cnt = 0;
      for (int i = 0; i < 26; i++){
        cnt += v[i].query(l - 1,r);
      }
      cout << cnt << endl;
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
