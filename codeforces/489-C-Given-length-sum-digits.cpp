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
  int m, s;
  cin >> m >> s;
  if (m == 0 || s == 0){
    cout << "-1 -1" << endl;
    return;
  }
  vector<int> sm;
  vector<int> lg;
  while (s){
    if (s > 9){
      s-= 9;
      sm.pb(9);
      lg.pb(9);
    }
    else{
      if (sm.size() < m - 1){
        sm.pb(1);
        sm.pb(s - 1);
      }
      else{
        sm.pb(s);
      }
      lg.pb(s);
      s = 0;
    }
  }
  if (sm.size() > m){
    cout << "-1 -1" << endl;
    return;
  }
  // Smallest number
  cout << sm[sm.size() - 1];
  cout << string(m - sm.size(), '0');
  
  for (int i = sm.size() - 2; i >= 0; i--){
    cout << sm[i];
  }

  cout << " ";
  for (int i = 0; i < sm.size() ; i++){
    cout << lg[i];
  }
  cout << string(m - (sm.size()), '0');
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
