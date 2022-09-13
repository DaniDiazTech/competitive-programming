/*
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

  pair<string, int> arr[n];

  unordered_map<string, int> mp;
  unordered_map<string, int> finalmp;

  vector<string> winners;


  for (int i = 0; i < n; i++){
    string s;
    int x;
    cin >> s >> x;
    arr[i] = {s, x};  
    mp[s] = mp[s] + x;
  }
  
  int mx = MIN;

  for (auto& x: mp){
    if (x.ss > mx){
      mx = x.ss;
    }
  }

  for (auto& x: mp){
    if (x.ss == mx){
      winners.pb(x.ff);
    }
  }
  bool ok = 1;

  for  (int i = 0; i < n; i++){
    if (!ok) break;

    string s = arr[i].ff;
    int x = arr[i].ss;
    finalmp[s] = finalmp[s] + x;

    if (finalmp[s] >= mx){
      for (auto w: winners){
        if (s == w){
          ok = 0;
          cout << s << endl;
          break;
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int tc = 1;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
