// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;
typedef vector<int> vii;

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

struct stree{
  int size;
  vii t;
  int neutral = 0;
  int lc(int x){return 2 * x + 1;}
  int rc(int x){return 2 * x + 2;}
  void merge(int x){
    t[x] = t[lc(x)] + t[rc(x)];
  }

  void init(int n){
    size = 2;
    while (size < n) size *= 2;
    t.assign(2 * size, neutral);
  }

  void build(vii &a, int x , int lx, int rx){
    if (rx - lx == 1){
      if (lx < (int)a.size())
        t[x] = a[lx];
      return;
    }
    int m = (lx + rx) /2;
    build(a, lc(x), lx, m);
    build(a, rc(x), m, rx);
    merge(x);
  }

  void build(vii &a){
    build(a, 0,0,size);
  }
  
  void update(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      t[x] = v;
      return;
    }
    int m= (lx + rx) / 2;
    if (u < m){
      update(u,v,lc(x), lx, m);
    }
    else{
      update(u,v,rc(x), m, rx);
    }
    merge(x);
  }

  void update(int u, int v){update(u,v,0,0,size);}

  int query(int k, int x, int lx, int rx){
    // cout << "SEARCHING: " << k << " RANGE: " << lx << " " << rx << endl;
    if (rx - lx == 1){
      update(lx, 0);
      return lx + 1;
    }
    int m = (lx + rx) / 2;
    if (k <= t[rc(x)]){
      return query(k, rc(x), m, rx);
    }
    else{
      return query(k - t[rc(x)], lc(x), lx, m);
    }
  }

  int query(int k){
    return query(k, 0,0,size);
  }
};
// int arr[MAX];
void solve(){
  int n;
  cin >> n;
  vii b(n, 1);
  stree st;
  st.init(n);
  st.build(b);
  int a[n];
  vii ans;
  forn(i,n) cin >> a[i];
  for (int i = n - 1; i >= 0; i--){
    int x = st.query(a[i] + 1);
    // cout << "FOUND: " << x << endl;
    ans.pb(x);
  }
  for (int i = n - 1; i >= 0; i--) cout << ans[i] << " ";
  cout << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
