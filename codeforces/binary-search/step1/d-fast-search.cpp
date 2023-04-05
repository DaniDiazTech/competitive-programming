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
  cin >> n;
  int a[n];
  forn(i,n) cin >> a[i];
  sort(a, a + n);
  cin >> q;
  // Two pointers
  forn(i,q){
    int x, y; cin >> x >> y;
    // Closest from the left for x and closet from the right for y
    int l1 = -1, r1 = n;
    while (l1 + 1 < r1){
      int m = (l1 + r1) /2;
      if (a[m] < x){
        l1 = m;
      }
      else r1 = m;
      // Ans in r
    }
    int l2 = -1, r2 = n;
    while (l2 + 1 < r2){
      int m = (l2 + r2) /2;
      if (a[m] <= y){
        l2 = m;
      } 
      else r2 = m;
    }
    cout << (l2 - r1) + 1 << endl;
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
