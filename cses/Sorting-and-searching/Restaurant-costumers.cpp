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
void solve_two_pointers(){
  int n;
  cin >> n;
  int a[n], b[n];
  forn(i, n){
    cin >> a[i] >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);

  int best = 0;
  int cnt = 0;
  int i = 0, j = 0;

  for (i = 0; i < n; i++){
    cnt++;
    while (a[i] >= b[j]){
      cnt--;
      j++;
    }
    best = max(cnt, best);
  }
  cout << best << endl;
}

void solve(){
  int n;
  cin >> n;
  vector<pair<int, int>> a;

  forn(i, n){
    int start, end;
    cin >> start >> end;
    // Adds one if we hit the time when a person
    // enters the restaurant
    a.pb({start, 1});

    // Decreases one if we hit the leave time
    // of a costumer
    a.pb({end, -1});
  }
  sort(a.begin(), a.end());
  int cnt, best;
  cnt  = best  = 0;
  for (auto x: a){
    cnt += x.second; 
    best = max(best, cnt);
  }
  cout << best << endl;

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
