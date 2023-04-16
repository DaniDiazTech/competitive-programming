// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

vector<int> G[MAX];
int dis[MAX]; 
int parent[MAX]; 

void solve(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y; 
    G[x].pb(y);
    G[y].pb(x);
  }
  deque<int> q;  
  q.pb(1);
  bool ok = true;

  while (!q.empty() && ok){
    int u = q.front();
    cout << u << endl;
    q.pop_front();

    for (auto v: G[u]){
      cout << "Parent: " << u << ": " << v << endl;
      if (dis[v] != 0){
        continue;
      }
      parent[v] = u;
      dis[v] = dis[u] + 1;
      q.emplace_back(v);
      if (v == n){
        ok = false;
        break;
      }
    }

  }

  if (dis[n] == 0){
    cout << "IMPOSSIBLE";
    return;
  }
  cout << dis[n] << endl;
  int p = parent[n];
  while (p != 0){
    cout << p << ' ';
    p = parent[p];
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
