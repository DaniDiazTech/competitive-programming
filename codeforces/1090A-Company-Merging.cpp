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

const int MAX = 2 * 1e5;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


// Solution
void solve(){
  int n, m, k;
  cin >> n;

  


  map<int, pair<int, int>> mp;

  // index, max, sum
  vector<int> maxmincompany = {-1, -1, -1};

  for (int i = 0; i < n; i++){
    cin >> m;

    int s = 0;

    int internmx = -1;

    for (int j = 0; j < m; j++){
      cin >> k;
      internmx = max(k, internmx); 
      s += k;
    }

    if (maxmincompany[0] == -1 || internmx > maxmincompany[1]){
      maxmincompany = {i, internmx, s};
    }
    else if (internmx == maxmincompany[1]){
      if (s < maxmincompany[2]){
        maxmincompany = {i, internmx, s};
      }
    }

    mp[i] = mk(internmx, m);
  }


  int mx = maxmincompany[1];

  int sum = 0;
  for (auto x: mp){
    if (x.first == maxmincompany[0]){
      continue;
    }
    int diff = mx - x.second.first;
    sum += diff * (x.second.second);
  }

  cout << sum << endl;
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
  // cin >> tc;

  // c_arr();
  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
