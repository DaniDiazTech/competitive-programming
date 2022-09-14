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
int dl(int n){
  return to_string(n).size();
}
 // Solution
void solve(){
  int n;
  cin >> n;

  priority_queue<int> qa;
  priority_queue<int> qb;

  forn(i, n){
    int x;
    cin >> x;
    qa.push(x);
  }
  forn(i, n){
    int x;
    cin >> x;
    qb.push(x);
  }
  int ans = 0;
  while (!qa.empty()){
    if (qa.top() == qb.top()){
      qa.pop(); qb.pop();
      continue;
    }
    ans++;
    if (qa.top() > qb.top()){
      int d = dl(qa.top());
      qa.pop();
      qa.push(d);
    }
    else{
      int d = dl(qb.top());
      qb.pop();
      qb.push(d);
    }
  } 

  cout << ans << endl;
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
