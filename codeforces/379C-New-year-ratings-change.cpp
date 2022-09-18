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


 // Solution
void solve(){
  int n;
  cin >> n;
  vector<pair<int, int>> a;

  forn(i, n){
    int x;
    cin >> x;
    a.pb(mk(x, i));
  }

  sort(a.begin(), a.end());

  vector<pair<int, int>> ans;
  ans.pb(a[0]);
  for (int i = 1; i < n;i++){
    if (a[i].first <= ans[i - 1].first){
      ans.pb(mk(ans[i - 1].first + 1, a[i].second));
    }
    else{
      ans.pb(mk(a[i].first, a[i].second));
    }
  }  

  vector<int> v(n);
  forn(i, n){
    auto x = ans[i];
    // cout << x.first << x.second << endl; 
    v[x.second]=x.first;
  }

  forn(i, n){
    cout << v[i];
    if (i != n - 1) cout << " ";
  }

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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
