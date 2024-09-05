// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


const int inf = 2e9 ;
struct segtree{
  int N;
  vector<int> t;
  segtree(vector<int> &a){
    N = a.size();
    t.assign(4 * N, inf);
    build(1, 0, N - 1, a);
  }
  void build(int v, int l, int r, vector<int> &a){
    if (l == r){
      t[v] = a[l];
      return;
    }
    int m = (l + r)/ 2;
    build(2 * v, l, m , a);
    build(2 * v + 1, m + 1, r , a);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }

  void update(int v, int l, int r, int pos, int val){
    if (l == r){
      t[v] += val;
      return;
    }
    int m =(l + r) /2 ;
    if (pos <= m){
      update(2 * v , l, m, pos, val);
    }
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
  void update(int pos, int val){
    update(1, 0, N -1 , pos, val);
  }

  int query(int v, int tl, int tr, int l ,int r){
    if (l > r) return inf;
    if (tl == l && tr == r){
      return t[v];
    }
    int tm = (tl + tr)  /2 ;
    return min(
      query(2 * v, tl, tm, l, min(r, tm)),
      query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
    );
  }
  
  int query(int l, int r){
    return query(1, 0, N -1 , l, r);
  }
};


void solve(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    b[i] = a[i] + i;
  }
  segtree t1(b);

  for (int i = 0;i < n; i++){
    b[i] = a[n - i - 1] + i;
  }
  segtree t2(b);

  while (q--){
    int op; cin >> op;
    if (op == 1){
      int j, x;
      cin >> j >> x;
      j--;
      t1.update(j, -a[j] + x);
      t2.update(n - j - 1, -a[j] + x);
      a[j] = x;
    }
    else{
      int j;
      cin >> j;
      j--;
      int x = t1.query(j, n - 1) - j;
      int y = t2.query(n - j - 1, n - 1) - (n - j - 1);
      cout << min(x, y) << endl;
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
