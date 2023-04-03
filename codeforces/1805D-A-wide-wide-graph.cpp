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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

vector<int> g[MAX];

void dfs(int u, int p, int h, vector<int> &d){
  d[u] = h;
  for (auto v: g[u]){
    if (v != p){
      dfs(v, u, h + 1, d);
    }
  }
}

void solve(){
  int n;
  cin >> n;
  forn(i,n - 1){
    int a, b; cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  vector<int> d(n + 1), d2(n + 1);

  dfs(0, -1, 0, d);
  int a = max_element(all(d)) - d.begin();
  dfs(a, -1, 0, d);
  // Farthest element from a
  int b = max_element(all(d)) - d.begin();
  dfs(b, -1, 0, d2);
  // Maximum distance between edges
  forn(i,n){
    d2[i] = max(d2[i], d[i]);
  }

  sort(all(d2));

  int ans = 0; 
  fore(i,1,n + 1){
    while (ans < n && d2[ans] < i){
      ans++;
    }
    cout << min(n, ans) << " ";
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
