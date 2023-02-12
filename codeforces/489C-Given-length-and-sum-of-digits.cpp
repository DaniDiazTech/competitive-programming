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
  int n, m;
  cin >> n >> m;
  if (m == 0){
    if (n == 1){
      cout << "0 0" << endl;
    }
    else cout << "-1 -1" << endl;
    return;
  }
  vector<int> sm;
  vector<int> lg;
  while (m > 9){
    m -= 9;
    sm.pb(9);
    lg.pb(9);
  }
  if (m > 0){
    lg.pb(m); 

    if (sm.size() + 1 < n){
      // I can insert a 1
      if (m > 1)
        sm.pb(m - 1);
      sm.pb(1);
    }
    else{
      sm.pb(m);
    }
  }


  if (lg.size() > n || sm.size() > n){
    cout << "-1 -1" << endl;
    return;
  }

  // Reconstruct the answer
  // sm
  cout << sm.back();
  cout << string(n - sm.size(), '0');
  for (int i = sm.size() - 2; i >= 0; i--){
    cout << sm[i];
  }
  cout  << " ";

  // lg
  for (int i = 0; i < (int)lg.size(); i++){
    cout << lg[i];
  }
  cout << string(n - lg.size(), '0') << endl;

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
