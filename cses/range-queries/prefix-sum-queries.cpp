// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
 
struct vertex{
  ll sum, ans;
  vertex(){
    sum = ans = 0;
  }
  vertex(ll s, ll a){
    sum = s;
    ans = a;
  }
};
 
struct segtree{
  vector<vertex> t;
  int N;
  segtree(vector<ll> &a){
    N = a.size();
    t.assign(4 * N, vertex());
    build(1, 0, N -1 , a);
  }
 
  vertex combine(vertex a, vertex b){
    return vertex(a.sum + b.sum, max(a.ans, a.sum + b.ans));
  }
 
  void build(int v, int l, int r, vector<ll> &a){
    if (l == r){
      t[v] = vertex(a[l], max(0ll, a[l]));
      return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m, a);
    build(2 * v + 1, m + 1, r, a);
    t[v] = combine(t[2 * v], t[2 * v + 1]);
  }
 
  void update(int v, int l, int r, int pos, ll val){
    if (l == r){
      t[v] = vertex(val, max(0ll, val));
      return;
    }
    int m = (l + r) / 2;
    if (pos <= m){
      update(2 * v, l, m, pos, val);
    }
    else{
      update(2 * v + 1, m + 1, r , pos, val);
    }
    t[v] = combine(t[2 * v], t[2 * v + 1]);
  }
 
  void update(int pos, int val){
    update(1, 0, N -1 , pos, val);
  }
 
  vertex query(int v , int tl, int tr, int l, int r){
    if (l > r) return vertex();
    if (tl == l && tr == r){
      return t[v];
    }
    int tm = (tl + tr)/ 2;
    return combine(
      query(2 * v, tl, tm, l, min(tm, r)),
      query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r)
    );
  }
 
  ll get(int l, int r){
    return query(1, 0, N -1 , l, r).ans;
  }
};
 
void solve(){
  int n, q;
  cin >> n >> q;
 
  vector<ll> a(n);
  for (auto &x: a) cin >> x;
  segtree st(a);
  while(q--){
    int op, l, r; cin >> op >> l >> r;
    if (op == 1){
      st.update(l - 1, r);
    }
    else{
      cout << st.get(l -1 , r- 1) << endl;
    }
  }
  
}
 
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
 
  int tc = 1;
  // cin >> tc;
 
  for (int t = 1; t <= tc; t++){
    solve();
  }
}