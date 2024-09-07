// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 1e5 + 10;
int t[4 * N];

int n, q;

void build(int v, int l, int r, int a[]){
  if (l == r) t[v] = a[l];
  else{
    int m = (l + r) / 2;
    build(2 * v, l, m, a);
    build(2 * v + 1, m + 1, r, a);
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r){
  if (l > r) return 0;
  if (tl == l && tr == r){
    return t[v];
  }
  int m = (tl + tr) / 2;
  return gcd(
    query(2 * v, tl , m, l, min(r, m)),
    query(2 * v + 1, m + 1 , tr,  max(l, m + 1), r)
  );
}
int query(int l, int r){
  return query(1, 0, n - 1, l, r);
}

void solve(){
  cin >> n;
  int a[n];
  map<int, vector<int>> mp;
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    mp[a[i]].push_back(i);
  }
  build(1, 0, n - 1, a);

  cin >> q;
  while (q--){
    int l, r; cin >> l >> r;
    l--; r--;

    int x = query(l, r);
    // search x
    int ans = r - l  + 1;

    auto itl = lower_bound(mp[x].begin(), mp[x].end(), l);
    if (itl == mp[x].end()){
      cout << ans << endl;
      continue;
    }
    auto itr = upper_bound(mp[x].begin(), mp[x].end(), r);
    ans -= (int)(itr - itl); 
    cout << ans << endl;
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
