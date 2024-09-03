// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 3e5 + 2;
int t[N * 4];
int n, q;
void update(int v, int tl, int tr, int l, int r, int val){
  if (l > r) return;
  if (tl == l && tr == r){
    t[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  update(2 * v, tl, tm, l, min(r, tm), val);
  update(2 * v + 1, tm + 1, r, max(l, tm + 1), r, val);
}

void update(int l, int r, int val){
  update(1, 0, n - 1, l, r, val);
}

void prop(int v, int tl, int tr){
  if (tl == tr){
    return;
  }
  int tm = (tl + tr) / 2;
  if (t[2 * v] == 0) t[2 * v] = t[v];
  prop(2 * v, tl, tm);
  if (t[2 * v + 1] == 0) t[2 *v + 1] = t[v];
  prop(2 *v + 1, tm + 1, tr);
}

int query(int v, int tl, int tr, int pos){
  if (tl == tr){
    return t[v];
  }
  int tm = (tl + tr) / 2;
  if (tl <= pos && pos <= tm){
    return query(2 * v, tl, tm, pos);
  }
  else{
    return query(2 * v + 1, tm + 1, tr, pos);
  }
}

int query(int pos){
  return query(1, 0, n - 1, pos);
}

void solve(){
  cin >> n >> q;
  vector<vector<int>> a;
  for (int i = 0;i < q; i++){
    int l, r, val;
    cin >> l >> r >> val;
    l--;
    r--;
    a.push_back({l, r, val});
  }
  reverse(a.begin(), a.end());

  for (int i =0;i < q; i++){
    update(a[i][0], a[i][1], a[i][2]);
  }
  prop(1, 0, n - 1);

  for (int i = 0;i < n; i++){
    int x = query(i);
    cout << (x == i + 1 ? 0: x) << " ";
  }
  cout << endl;

  for (int i = 0;i < 4 * n ; i++){
    cout << t[i] << ' ';
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
