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
  string s, t, pref; cin >> s >> t;
  n = s.size(), m = t.size();

  // Start position
  for (int i = 0; i < n; i++){ // n
    // Substring from i -> Pick with chip
    string pos = "", rev = "";
    for (int j = i; j < n; j++){ // n
      pos += s[j];
      // Reverse substring
      // I don't need all the cases, only the ones that match the length
      int start = 2 * j - m - i + 1;
      int steps =  m - j + i - 1;
      if (start < 0 || steps < 0 || start + steps > n){
        continue;
      }
      rev = s.substr(start, steps);
      reverse(rev.begin(), rev.end());
      
      // cout << pos + rev << endl;
      if (pos + rev == t){
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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
