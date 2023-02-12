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
  int n, k;
  cin >> n >> k;
  vector<int> a;
  forn(i,n){
    int x; cin >> x;
    if (x  != 0)
      a.pb(x);
  }

  sort(a.begin(), a.end());

  for (int i = 0 ; i < (int)a.size() - 1; i++){
    if (k % a[i] != 0) continue;
    int search = k / a[i]; 
    int l = i + 1, r = a.size() - 1;
    while (l <= r){
      int m = (l +  r) / 2;
      if (a[i] * a[m] == k){
        cout << a[i] << " " << a[m];
        return;
      }

      if (a[i] * a[m] > k){
        r =  m - 1;
      }
      else{
        l = m + 1; 
      }
    }
  }
  cout << -1;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    if (t > 1) cout << endl; 
    solve();
  }
  return 0;
}
