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

// int arr[MAX];
void solve_first_method(){
  int n;
  cin >> n;
  vector<pii> a;
  forn(i, n){
    int x, y; cin >> x >> y;
    a.pb({x, y});
  }
  sort(a.begin(), a.end());

  int cnt = 0;
  int current = 0;
  for (int  i = 0; i < n ; i++){
    if (i == 0){
      current = a[i].second;
      cnt++;
      continue;
    }
    // Conflict
    if (current > a[i].first){
      // pick the current
      current = min(a[i].second, current);
    }
    else{
      current = a[i].second;
      cnt++;
    }
  }
  cout << cnt;
}

bool cmp(pii x, pii y){
  return x.second < y.second;
}

void solve(){
  int n; cin >> n;
  vector<pii> v;
  forn(i,n){
    int x,y; cin >> x >> y;
    v.pb({x, y});
  }
  // Sort with second element
  sort(v.begin(), v.end(), cmp);

  int current_end_time = 0;
  int cnt = 0;
  for (auto movie: v){
    if (movie.first >= current_end_time){
      cnt++;
      current_end_time = movie.second;
    }
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
