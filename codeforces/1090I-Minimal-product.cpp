/*
Made by Daniel Diaz (Danidiaztech)
Problem name: 
Algorithm or Logic:
Complexity: 
Link:
More info: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
// Templates
#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define int long long
// #define ull unsigned int
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
const int MOD = pow(2, 32) - 1;
 
// int arr[MAX];
 
 // Solution
void solve(){
  int n,l, r;
  int x,y,z,b1,b2;
  cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
 
  int bi[n];
  int ai[n];
 
  bi[0]=b1;bi[1]=b2;
  
  for (int i = 2; i < n;i++){
    bi[i] = (bi[i-2]*x + bi[i-1]*y + z) &MOD; 
  }
  forn(i,n){
    ai[i] = (int)((int)bi[i] % (r - l + 1)) + l;
  }
 
  int minimum_p = INF;

  // First case
  int best = ai[0];
  // min
  for (int i = 1; i < n; i++){
    if (ai[i] > best){
      minimum_p = min(minimum_p, ai[i] * best);      
    }
    best = min(best, ai[i]);
  }

  best = ai[n - 1];
  // max
  for (int i = n - 2; i >= 0; i--){
    if (best > ai[i]){
      minimum_p = min(minimum_p, ai[i] * best);      
    }
    best = max(best, ai[i]);
  }
  
  if (minimum_p != INF) cout << minimum_p << endl;
  else cout << "IMPOSSIBLE" << endl;
}
 
int32_t main() {
  fastInp;
 
  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif
 
  // Testscases
  int tc = 1;
  cin >> tc;
 
  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
 
  return 0;
}