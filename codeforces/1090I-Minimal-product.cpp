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
#define int long long int
#define ull unsigned int
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
const int MOD = pow(2, 32);

// int arr[MAX];

 // Solution
void solve(){
  int n,l,r,x,y,z,b1,b2;
  cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;

  ull bi[n];
  int ai[n];

  bi[0]=b1;bi[1]=b2;

  for (ull i = 2; (ull)i < (ull)n;i++){
    bi[i] = (bi[i-2]*x + bi[i-1]*y + z); 
  }
  forn(i,n){
    ai[i] = ((int)bi[i] % (r - l + 1)) + l;
  }

  // forn(i, n) cout << bi[i] << " ";
  // cout << endl;
  // forn(i, n) cout << ai[i] << " ";
  // cout << endl;

  // for (auto x: v) cout << x << " ";
  // cout << endl;

  int mn = ai[0];
  int mx = ai[0];
  int minimum_p = INF;
  
  bool possible = false;
  for (int i = 1; i < n; i++){
    if (ai[i - 1] < ai[i]){
      possible = true;
      if (ai[i] > 0){
        minimum_p = min(mn * ai[i], minimum_p);
      } 
      else{
        minimum_p = min(mx * ai[i], minimum_p);
      }
      mn = min(ai[i], mn);
      mx = max(ai[i], mx);
    }
  }
  
  if (possible) cout << minimum_p << endl;
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
