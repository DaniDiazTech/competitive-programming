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
#define sz(x) (int)x.siz() 

typedef pair<int, int> pii;
typedef vector<int> vii;

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

int siz = 2;
vector<pii> t;

void init(int n){
  siz = 2;
  while (siz < n) siz *= 2;
  t.assign(2 * siz, {-1,-1});
}

void build(vii &a, int x, int lx, int rx){
  if (rx - lx == 1){
    if (lx < (int)a.size())
      t[x] = {a[lx], lx};
    return;
  }
  int m = (lx + rx) /2 ;
  int lc = (2 *x + 1);
  int rc = lc + 1;
  build(a, lc, lx, m);
  build(a, rc, m, rx);
  if (t[lc].ff >= t[rc].ff){
    t[x] = t[lc];
  }
  else{
    t[x] = t[rc];
  }
}

pii query(int l, int r, int x, int lx, int rx){
  if (lx >= r || rx <= l) return {-1,-1};
  if (lx >= l && rx <= r) return t[x];
  int m = (lx + rx) /2 ;
  pii q1 = query(l,r,2 * x + 1, lx, m);
  pii q2 = query(l,r, 2* x + 2, m, rx);
  if (q1.ff >= q2.ff){
    return q1;
  }
  else return q2;
}

pii query(int l, int r){
  return query(l,r,0,0,siz);
}

void solve(){
  int n;
  cin >> n;
  vii a(n);
  vector<pii> v;
  forn(i,n){
    cin >> a[i];
    v.pb({a[i], i});
  }
  sort(v.begin(), v.end());

  init(n);
  build(a, 0,0,siz);
  int q;
  cin >> q;
  forn(i,q){
    int l, r; cin >> l >> r;
    cout << query(l, r + 1).ss << endl;
  }
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
