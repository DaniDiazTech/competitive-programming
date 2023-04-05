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

// int arr[MAX];
void solve(){
  int n, q;
  cin >> n >> q;
  int a[n];
  forn(i,n) cin >> a[i];

  while (q--){
    int x; cin >> x;
    int l = 0, r = n-1;
    bool ok = 0;
    while (l <= r){
      int mid = (l + r) >> 1;
      if (a[mid] == x){
        ok = 1;
        break;
      }
      else if (a[mid] > x){
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
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
