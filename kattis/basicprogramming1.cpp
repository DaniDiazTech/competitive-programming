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
void solve(){
  int n, t;
  cin >> n >> t;

  int a[n];
  int s, se;
  s = se = 0;
  string abc = "abcdefghijklmnopqrstuvwxyz", ans = "";
  forn(i,n){
    cin >> a[i];
    s += a[i];
    se += a[i] % 2 == 0 ? a[i]: 0;
    ans += abc[a[i] % 26];
  }
  if (t == 1){
    cout << 7;

  }
  else if (t == 2){
    cout << (a[0] > a[1] ? "Bigger": (a[0] == a[1] ? "Equal" : "Smaller"));
  }
  else if (t == 3){
    // Median:
    sort(a, a + 3);
    cout << a[1];
  }
  else if (t == 4){
    cout << s;
  }
  else if (t == 5){
    cout << se;
  }
  else if (t == 6){
    cout << ans;
  }
  else{
    set<int> s;
    int i = 0;
    while (true){
      if (i >= n){
        cout << "Out";
        return;
      }
      if (s.count(i)){
        cout << "Cyclic";
        return;
      }
      if (i == n - 1 ){
        cout << "Done";
        return;
      }
      s.insert(i);
      i = a[i];
    }
  }
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
