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

// int arr[MAX];

 // Solution
void solve(){
  int n,m, a, b;

  cin >> n >> m;

  vector<int> v(n + 1);

  map<int, set<int>> mp;

  if (n * (n - 1) / 2 <= m){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= m; i++){
    cin >> a >> b;
    mp[a].insert(b); mp[b].insert(a);
 }

  int ft = -1, st = -1;
  // Iterate over n
  for (int i = 1; i <= n; i++){
    if (ft != -1) break;
    if ((int)mp[i].size() < n - 1){
      ft = i;
      for (int j = 1; j <= n; j++){
        if (mp[i].find(j) == mp[i].end() && j != ft){
          st = j;
          break;
        }
      }
    } 
  }

  // cout << ft << st << endl;
  int p = 3;
  for (int i = 1; i <= n; i++){
    if (i == ft) cout << "1 ";
    else if (i == st) cout << "2 ";
    else{
      cout << p << " ";
      p++;
    }
  }
  cout << endl;
  p = 3;
  for (int i = 1; i <= n; i++){
    if (i == ft || i == st) cout << "1 ";
    else{
      cout << p << " ";
      p++;
    }
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
