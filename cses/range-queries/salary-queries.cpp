// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
 
// Other pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
struct segtree{

  vector<int> t;
  int N;

  segtree(vector<int> &a){
    N = a.size();
    t.assign(4 * N, 0);
    build(1, 0, N - 1, a);
  }
  
  void build(int v, int l, int r, vector<int> &a){
    if (l == r){
      t[v] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m, a);
    build(2 * v + 1, m + 1, r, a);
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  void update(int v, int tl, int tr, int pos, int val){
    if (tl == tr){
      t[v] += val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm){
      update(2 * v, tl , tm , pos, val);
    }
    else{
      update(2 * v + 1, tm + 1, tr, pos, val);
    }
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  void update(int pos, int val){
    update(1, 0, N - 1, pos, val);
  }

  int query(int v, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
      return t[v];
    }
    int tm = (tl + tr) / 2 ;
    if (l > tm){
      return query(2 * v + 1, tm + 1, tr, l, r);
    }
    else if (r <= tm){
      return query(2 * v, tl, tm, l, r);
    }
    else{
      return query(2 * v + 1, tm + 1, tr, tm + 1, r) + query(2 * v, tl, tm, l, tm);
    }
  }

  int query(int l, int r){
    return query(1, 0, N - 1, l, r);
  }

  void print(){
    for (auto x: t) cout << x << " ";
    cout << endl;
  }
};
 
void solve(){
  int n, m, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> b;
  vector<vector<int>> queries;
  for (auto &x: a){
    cin >> x; b.push_back(x);
  }
  int id  = 1;
 
  for (int i = 0;i < q; i++){
    char op; cin >> op;
    int u, v; cin >> u >> v;
    queries.push_back({op == '?', u, v});
    if (op == '?'){
      b.push_back(u);
    }
    b.push_back(v);
  }

  sort(b.begin(), b.end());
 
  unordered_map<int,int> from;
 
  for (auto x: b){
    if (from.count(x)) continue;
    from[x] = id;
    id++;
  }
 
  m = id;
 
  vector<int> f(m);
  for (auto x: a){
    f[from[x]]++;
  }
 
  segtree st(f);
 
  for (int i =0 ;i < q; i++){
    int u = queries[i][1], v = queries[i][2];
    if (queries[i][0]){
      cout << st.query(from[u], from[v])<< endl;  
    }
    else{
      u--;
      st.update(from[a[u]], -1);
      a[u] = v;
      st.update(from[a[u]], 1);
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