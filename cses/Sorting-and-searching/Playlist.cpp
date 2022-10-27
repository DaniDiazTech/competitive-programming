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
void solve_1(){
  int n;
  cin >> n;
  vector<int> a(n + 1);
  forn(i,n) cin >> a[i + 1];

  int i = 1;
  int ans = 0;
  // Number: Position
  map<int, int> mp; 
  for (int j = 1;  j <= n; j++){
    // for (auto x: mp) cout << x.first << " " << x.second << endl;
    if (i < mp[a[j]] + 1){
      i =  mp[a[j]]+ 1;
    }
    ans = max(ans, j - i + 1);
    mp[a[j]] = j;
  }


  cout << ans << endl;
}

// void solve(){
//   int n;
//   cin >> n;
//   vector<int> a(n + 1);
//   forn(i,n) cin >> a[i + 1];
//   int j = 1;
//   int ans = 0;
//   set<int> s;
//   for (int i = 1; i <= n; i++){
//     if(!s.count(a[i])){
//       // Can increment j
//       while (!s.empty() && a[j] != a[i]){
//         s.erase(a[j]);
//         j++;
//       }
//       j++;
//     }
//     s.insert(a[i]);
//     ans = max(ans, i - j + 1);
//   }


//   cout << ans << endl;
// }


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
