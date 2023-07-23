// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;
typedef vector<int> vii;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int mod = 1e9 + 7;

int pos[MAX + 200];

// Exclusive in rx
struct segtree {
  int size;
  vector<pii> t;
  pii NEUTRAL = {2, 0};
  int lc(int x){
    return 2 * x + 1;
  }
  int rc(int x){
    return 2 * x + 2;
  }
  int m(int lx, int rx){return (lx + rx) / 2;}
  void merge(int x){
    if (t[lc(x)].ff <= t[rc(x)].ff){
      t[x] = t[lc(x)];
    }
    else t[x] = t[rc(x)];
  }
  void init(int n){
    size = 1;
    while (size < n) size *= 2;
    t.assign(2 * size, NEUTRAL); 
  } 
  void build(vii &a, int x, int lx, int rx){
    if (rx - lx == 1){
      t[x] = {a[lx], lx};
      return;
    }
    build(a, lc(x), lx, m(lx, rx));
    build(a, rc(x), m(lx, rx), rx);
    merge(x);
  }
 
  void build(vii &a){
    build(a, 0,0,size);
  }
 
  void update(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      t[x] = {v, u};
      return;
    }
    if (u < m(lx, rx)){
      update(u, v, lc(x), lx, m(lx, rx));
    }
    else{
      update(u, v, rc(x), m(lx, rx), rx);
    }
    merge(x);
  }
 
  void update(int u, int v){
    update(u, v, 0, 0, size);
  }
 
  pii query(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l) return NEUTRAL;
    if (lx >= l && rx <= r) return t[x];
    pii q1 = query(l, r, lc(x), lx, m(lx, rx));
    pii q2 = query(l,r, rc(x), m(lx, rx), rx);
    if (q1.ff <= q2.ff){
      return q1;
    }
    else return q2;
  }
 
  pii query(int l, int r){
    return query(l,r, 0, 0, size);
  }
};
const int c  = 1000000 + 10;
 
void solve(){
  int n;
  cin >> n;
  vector<int> v(c);
  int mx = 0;
  fore(i,1,n + 1){
    cin >> pos[i];
    v[pos[i]] = 1;
    mx = max(pos[i], mx);
  }  
  segtree st;
  st.init(sz(v));
  st.build(v);
  int q; cin >> q;
  while (q--){
    int x; cin >> x;
    int i = pos[x]; 
    pii qr = st.query(i +1, mx + 2);
    int ps = qr.ss;
    mx = max(ps, mx);
    pos[x] = ps;

    cout << ps << endl;
    st.update(i, 0);    
    st.update(ps, 1);    
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
