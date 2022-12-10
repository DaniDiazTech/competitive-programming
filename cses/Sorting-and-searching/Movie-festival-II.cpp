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

bool cmp(pii x, pii y){
  return x.second < y.second;
}
// int arr[MAX];
void solve(){
  int n, m;
  cin >> n >> m;
  vector<pii> movies;
  multiset<int> members;
  forn(i, m) members.insert(0);
  forn(i, n){
    int x, y;
    cin >> x >> y;
    movies.pb({x, y});
  }
  sort(movies.begin(), movies.end(), cmp);
  int cnt = 0;
  for (auto movie: movies){
    // cout << movie.first << " " << movie.second << endl;
    auto it = members.upper_bound(movie.first);
    if (it == begin(members)) continue;
    members.erase(--it);
    members.insert(movie.second);
    cnt++;
  }
  cout << cnt << endl;
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
