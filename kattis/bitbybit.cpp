// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
// #define int long long int
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
const int mod = 1e9 + 7;

// int arr[MAX];
void solve(){
  int n;
  while (cin >> n){
    if (n == 0) break;
    vector<int> b(32, -1);
    for (int i = 0; i < n; i++){
      string op; cin >> op;
      if (op == "CLEAR"){
        // Put 0 i x
        int j; cin >> j;
        // Turn off jth bit
        b[j] = 0;
     }
      if (op == "SET"){
        int j; cin >> j;
        b[j] = 1;
      }
      if (op == "OR"){
        int x, y; cin >> x >> y;
        if (b[x] == 1 || b[y] == 1){
          b[x] = 1;
        }
        else if (b[x] == 0 && b[y] == 0){
          b[x] = 0;
        }
        else b[x] = -1;
      }
      if (op == "AND"){
        int x, y; cin >> x >> y;
        if (b[x] == 1 && b[y] == 1){
          b[x] = 1;
        }
        else if (b[x] == 0 || b[y] == 0){
          b[x] = 0;
        }
        else b[x] = -1;
      }
    }
    for (int i = 31; i >= 0; i--){
      cout << (b[i] != -1 ? (b[i] ? '1': '0'): '?');
    }
    cout << endl;
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
