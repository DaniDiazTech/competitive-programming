// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 2e5 + 2;
int t[4 * N];
int n;

void update(int v, int l, int r, int pos, int val){
  if (l == r){
    t[v] = val;
    return;
  }
  int m = (l + r)/ 2;
  if (pos <= m){
    update(2 * v, l, m, pos, val);
  }
  else{
    update(2 * v + 1, m + 1, r, pos, val);
  }
  t[v] = t[2 * v] + t[2 * v + 1];
}

int query(int v, int tl, int tr, int l, int r){
  if (l > r) return 0;
  if (tl == l && tr == r){
    return t[v];
  }
  int tm = (tr + tl) / 2 ;
  return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1 , tm + 1, tr, max(l, tm + 1), r);
}
int query(int l, int r){return query(1, 0, n - 1,l, r);}

void solve(){
  cin >> n;
  int a[n];
  for (int i =0 ;i < n; i++){
    cin >> a[i];
  }

  for (int j = 0;j < n; j++){
    int x; cin >> x;
    int l = 0, r = n; 
    while (l + 1 < r){
      int m = (l + r) / 2;
      int q = query(l, m - 1);
      // left: l, l + 1, ..., m - 1
      if (m - l - q < x){
        x -= m - l - q;
        l = m; 
      } 
      else{
        r = m;
      }
    }
    update(1, 0, n - 1, l, 1);
    cout << a[l] << " ";
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
