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

 // Solution
void solve(){
  // Default queue: uses std::less as cmp
  vector<int> v = {1, 2, 8, 92, 12, 212, 3};
  priority_queue<int, vector<int>> Q(v.begin(), v.end());

  while (!Q.empty()){
    cout << Q.top() << " ";
    Q.pop(); // Pops largest element
  }

  cout << endl;

  // Smallest first
  priority_queue<int, vector<int>, greater<int>> Q2(v.begin(), v.end());

  while (!Q2.empty()){
    cout << Q2.top() << " ";
    Q2.pop(); // Pops smallest element
  }

  cout << endl;
  
  // Using custom comparator
  // Ascending order
  auto cmp = [](int a, int b){
    return a > b;
  };

  priority_queue<int, vector<int>, decltype(cmp)> Q3(v.begin(), v.end(), cmp);
  while(!Q3.empty()){
    cout << Q3.top() << " ";
    Q3.pop();
  }
  cout << endl;
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
