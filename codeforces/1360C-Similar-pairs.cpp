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
  int n;
  cin >> n;
  int odd, even;
  odd = even = 0;
  int a[n];

  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    if (x & 1) odd++;
    else even++;
    a[i] = x;
  }

  // Parity of even and odd is not the same
  // Example: 
  // Both even
  if (even % 2 == 0 && odd % 2 == 0){
    cout <<"YES"<< endl;
  }
  else{
    // Check for adjacent number
    sort(a, a + n); 
    for (int i = 0; i < n - 1; i++){
      if (a[i + 1] - a[i] == 1){
        cout << "YES" << endl;
        return;
      }
    }
    cout << "NO" << endl;
  }
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
    solve();
  }
  return 0;
}
