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
const int max_value = 400;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int a[MAX];
int fq[max_value + 5];
void solve(){
  int n;
  cin >> n;
  forn(i,n) cin >> a[i];
  // Counting sort
  forn(i,n){
    fq[a[i]]++;
  }

  int res[n];  
  for (int i = 0, j = 0; i <= max_value && j < n; i++){
    // cout << fq[i] << " ";
    for (int k = 0 ; k < fq[i]; k++){
      res[j] = i;
      j++;
    }
  }
  forn(i,n) cout << res[i] << " ";
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
