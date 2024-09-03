// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const ll inf = 1e12;

// Lazy update segment tree
// Count the number of minimums (Assumes there are no negative values: Count number of zeroes)
struct node{
  int mn, cnt;
  node(){
    mn = 0;
    cnt = 1;
  }
  node (int m, int c){
    mn = m;
    cnt = c;
  }
};



struct segtree{
  vector<ll> t;
  vector<ll> lazy;
  int N;
  segtree(int n){
    N = n;
    t.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }
  segtree(vector<ll> &a){
    N = a.size();
    t.assign(4 * N, 0);
    lazy.assign(4 * N, 0);
    build(1, 0, N - 1, a);
  }

  ll combine(ll a, ll b){
    return max(a, b);
  }

  void build(int v, int tl, int tr, vector<ll> &a){
    if (tl == tr){
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, a);
    build(2 * v + 1, tm + 1, tr, a);
    t[v] = combine(t[2 * v], t[2 * v + 1]);
  }

  void push(int v){
    t[2 * v] += lazy[v];
    t[2 * v + 1] += lazy[v];
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];

    lazy[v] = 0;
  }

  void update(int v, int tl, int tr, int l , int r, int val){
    if (l > r) return;
    if (tl == l && tr == r){
      t[v] += val;
      lazy[v] += val;
      return; 
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(tm, r), val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = combine(t[2 * v], t[2 * v + 1]);
  }

  void update(int l, int r, int val){
    update(1, 0, N - 1, l, r, val);
  }

  // mn, cnt in a range
  ll query(int v, int tl, int tr, int l, int r){
    if (l > r) return -1;
    if (tl == l && tr == r){
      return t[v];
    }
    int tm = (tl + tr) / 2;
    // need to push in order to calculate from children
    push(v);
    return combine( 
      query(2 * v, tl , tm, l, min(r, tm)),
      query(2 * v + 1, tm + 1 , tr, max(l, tm + 1), r)
    );
  }

  ll query(int l, int r){
    return query(1, 0, N - 1, l, r);
  }

};


void solve(){
  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (auto &x: a)cin >> x;
  segtree st(a);
  for (int i = 0;i < m; i++){
    char op; cin >> op;
    int l, r;
    cin >> l >> r;
    l--;r--;
    //update
    st.update(l, r, (op == '+' ? 1 : -1));
    cout << (st.query(0, n - 1)) << " ";
  }
  cout << endl;
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
