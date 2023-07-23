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

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

vii g[MAX];
int label[MAX], siz[MAX], nedges[MAX]; // label,siz, number of edges of each component 

void relabel(int u, int target){
  // set all vertex to target
  if (label[u] == target) return;
  label[u] = target;
  for (auto x: g[u]) {
    relabel(x, target);
  }
}

void merge(int u, int v){
  g[u].pb(v);
  g[v].pb(u);

  int lu= label[u];
  int lv = label[v];

  ++nedges[lu];

  if (lu == lv) return;

  // assum siz lv > lu
  if (siz[lu] > siz[lv]){
    swap(lu,lv);
    swap(u, v);
  }
  relabel(u, lv);
  siz[lv] += siz[lu];
  nedges[lv] += nedges[lu];
}

void solve(){
  int n, m;
  cin >> n >> m;
  fore(i,1,n + 1){
    siz[i] = 1;
    label[i] = i;
    nedges[i] = 0;
  }
  for (int i = 1; i<=m ;i++){
    int a, b; cin >> a >> b;
    merge(a,b);
  }
  bool f = 1;
  fore(i,1, n + 1){
    f &= (siz[label[i]] * (siz[label[i]] - 1)) / 2 == nedges[label[i]];
  }
  cout << (f ? yes : no) << endl;
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
