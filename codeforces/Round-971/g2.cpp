// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

struct segtree{
  vector<ll> t, sum;
  vector<bool> lazy;
  int N;
  segtree(int n){
    N = n;
    t.assign(4 * n, 0);
    sum.assign(4 * n, 0);
    lazy.assign(4 *n, 0);
  }

  void push(int v, int l, int r){
    if (lazy[v]){
      t[2 * v] = t[2 *v + 1] = t[v];
      lazy[v] = 0;
      lazy[2 * v] = lazy[2 * v + 1] = 1;

      int m = (l + r) / 2;
      sum[2 * v] = (m - l + 1) * t[v];
      sum[2 * v + 1] = (r - m) * t[v];
    }
  }

  void update(int v, int tl, int tr, int l , int r, int val){
    if (l > r) return;
    if (tl == l && tr == r){
      t[v] = val;      
      sum[v] = (tr - tl + 1) * t[v];
      lazy[v] = 1;
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val);
    update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, val);

    sum[v] = sum[2 *v] + sum[2 * v + 1];
  }  

  void update(int l, int r, int val){
    update(1, 0, N - 1, l, r, val);
  }

  ll query(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    if (tl == l && tr == r){
      return sum[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(tm, r)) + query(2 *v + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  ll query(int l, int r){
    return query(1, 0, N - 1, l, r);
  }

  void print(){
    cout <<"T: ";
    for (auto x: t)cout  << x << " ";
    cout << endl;
    cout << "S: ";
    for (auto x: sum)cout << x << " ";
    cout << endl;
  }
};

void solve(){
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> a(n), b(n), ans(n);
  for (auto &x: a) cin  >> x;

  for (int i = 0;i < n; i++){
    b[i] = a[i] - i;
  }

  int l = 0, r= 0;
  map<int,int> mp;
  priority_queue<pair<int,int>> pq;

  while (r - l + 1 <= k){
    mp[b[r]]++;
    pq.push({mp[b[r]], b[r]});
    r++;
  }

  while (r <= n){

    while (mp[pq.top().second] != pq.top().first){
      pq.pop();
    }
    ans[l] = pq.top().first;

    if (r == n) break;
    // update
    mp[b[r]]++;
    mp[b[l]]--;
    pq.push({mp[b[r]], b[r]});
    pq.push({mp[b[l]], b[l]});

    r++;
    l++;
  } 

  for (int i = 0;i <= n - k; i++){
    ans[i] = k - ans[i];
  }



  vector<vector<int>> queries;
  for (int i = 0;i < q; i++){
    int l, r; cin >> l >> r;
    l--;
    r -= k ;
    queries.push_back({l, r, i});
  }
  
  sort(queries.rbegin(), queries.rend());

  vector<pair<int,int>> s;
  s.push_back({-1, n - k + 1});

  segtree st(n - k + 1);

  int j = 0;

  vector<ll> final(q);
  for (int  x = n - k ; x >= 0; x--){
    while (s.back().first >= ans[x]) s.pop_back();
    int ind = s.back().second - 1;
    s.push_back({ans[x], x});

    // update segtree
    st.update(x, ind, ans[x]);

    while (j < q && queries[j][0] == x){
      final[queries[j][2]] = st.query(queries[j][0], queries[j][1]);
      j++;
    }
  }

  for (auto x: final) cout << x << endl;
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
