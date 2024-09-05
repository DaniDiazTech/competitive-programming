// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 2e5 + 10;
int t[4 * N];
int n, q;
// max segment tree with updates, and
// traversal in query

void build(int v, int l, int r, int a[]){
  if (l == r){
    t[v] = a[l];
    return;
  }
  int m = (l + r)/ 2;
  build(2 * v, l, m, a);
  build(2 * v + 1, m + 1, r, a);
  t[v] = max(t[2 *v], t[2 * v + 1]);
}

void update(int v, int tl, int tr, int pos, int val){
  if (tl == tr){
    t[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm){
    update(2 * v, tl, tm, pos, val);
  }
  else{
    update(2 *v  + 1, tm + 1, tr, pos, val);
  }
  t[v] = max(t[2 *v], t[2 * v + 1]);
}


// index of leftmost available hotel
int query(int v, int tl, int tr, int val){
  if (t[v] < val) return 0;
  if (tl == tr){
    update(1, 0, n - 1, tl, t[v] - val);
    return tl + 1;
  }

  int tm = (tl + tr) / 2;
  // first left
  if (t[2 * v] >= val){
    return query(2 * v, tl, tm, val);
  }
  else{
    return query(2 * v + 1, tm + 1, tr, val);
  }
}

void solve(){
  cin >> n >> q;
  int a[n];
  for (int i = 0;i < n; i++) cin >> a[i];
  build(1, 0, n - 1, a);
  while (q--){
    int x; cin >> x;
    cout << query(1, 0, n - 1, x) << " ";
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
