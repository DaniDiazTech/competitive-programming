// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int inf = 1e9;

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
  vector<node> t;
  vector<int> lazy;
  int N;
  segtree(int n){
    N= n;
    t.assign(4 * n, node());
    lazy.assign(4 * n, 0);
    build(1, 0, N - 1);
  }

  node combine(node a, node b){
    return node(min(a.mn, b.mn), (a.mn == b.mn ? a.cnt + b.cnt : (a.mn < b.mn ? a.cnt : b.cnt)));
  }

  void build(int v, int tl, int tr){
    if (tl == tr){
      return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = combine(t[2 * v], t[2 * v + 1]);
  }

  void push(int v){
    t[2 * v].mn += lazy[v];
    t[2 * v + 1].mn += lazy[v];
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];

    lazy[v] = 0;
  }

  void update(int v, int tl, int tr, int l , int r, int val){
    if (l > r) return;
    if (tl == l && tr == r){
      t[v].mn += val;
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
  node query(int v, int tl, int tr, int l, int r){
    if (l > r) return node(inf, 0);
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

  node query(int l, int r){
    return query(1, 0, N - 1, l, r);
  }

  // Count zeroes
  int get(int l, int r){
    node temp = query(l, r);
    return (temp.mn == 0 ? temp.cnt : 0);
  }
};


void solve(){
  int n, m;
  cin >> n >> m;

  segtree st(n);
  vector<pair<int,int>> v;
  for (int i =0 ;i < m; i++){
    int a, b; cin >> a >> b;
    v.push_back({a - 1, b - 2});
  }
  sort(v.begin(), v.end());
  // 0: 1 - 2
  // 1: 2 - 3
  // ..., n: n - 1
  for (int i = 0; i < m; i++){
    st.update(v[i].first, v[i].second, 1);
  }
  int ans = n - st.get(0, n -1 );

  int j = 0;
  // store reverse op
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  for (int i = 0;i < n; i++){
    // make
    while (j < m && v[j].first <= i){
      // remove range
      st.update(v[j].first, v[j].second, - 1);

      // add range
      st.update(0, v[j].first - 1, 1);
      st.update(v[j].second + 1, n - 1, 1);
      pq.push({v[j].second, v[j].first});
      j++;
    }
    // reverse
    while (pq.size() && i > pq.top().first){
      auto p = pq.top();
      pq.pop();
      int l =  p.second, r = p.first;

      st.update(l, r, 1);

      // add range
      st.update(0, l - 1, -1);
      st.update(r + 1, n - 1, -1);
    }
    ans = min(n - st.get(0, n - 1), ans);
  }
  cout << ans << endl;
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
