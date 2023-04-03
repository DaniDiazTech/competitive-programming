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
  int n, v;
  cin >> n >> v;
  int a[n], s[n];
  forn(i,n){
    cin >> a[i];
    s[i] = a[i];
  }
  // Sort array: O(n log n)
  sort(a, a + n);
  // First task:
  // Determine if there is a pair, i,j such that 0 <= i < j < n, and
  // a[i] == a[j]
  // Boolean

  // Solution
  cout << "Once the array is sorted all the duplicate numbers must be adjacent: O(n)" << endl << endl;
  bool found = 0;
  for (int i = 0; i < n - 1 && !found; i++){
    if (a[i] == a[i + 1]) found = 1;
  }
  cout << (found ? "There exist such pair": "NO") << endl;
  // Second task;
  // Given an integer v, find 2 integers a,b E S, such that a + b = v;
  cout << "Iterate through the array, and use binary search to look for the remaining integer to get a + b = v: O(n log n)" << endl << endl;
  found = 0;
  pii p = {-1, -1};
  for (int i =0 ; i < n - 1 && !found; i++){
    int x = v - a[i]; 
    if (x < 0) break;
    // Search space
    int l = i + 1, r = n  - 1;
    while (r >= l){
      int mid = (l + r) >> 1;
      if (a[mid] == x){
        found  = 1; p = {a[i], x};
        break;
      }
      else if (a[mid] > x){
        r = mid - 1;
      }
      else l = mid + 1;
    }
  }
  if (found){
    cout << "Found pair:  (" << p.ff << ", " << p.ss << ")\n"; 
  }
  else cout << "2. Not such pair exists" << endl;
  cout << "Same solution for 3, since I've already sorted the array";

  // Print integers that fall in range [a, b];
  int aa, bb; cin >> aa  >> bb;
  // O(n) -> Single iteration 
  cout << "\nIntegers in range [a,b]\n";
  for (int i = 0; i < n; i++){
    if (a[i] >= aa && a[i] <= bb)
      cout << a[i] << " ";
    if (a[i] > bb) break;
  }

  // Use unsorted array
  // Find longest increasing subsequence
  int mx = -1;
  int cnt = 1;
  for (int i = 1; i < n; i++){
    if (s[i - 1] <= s[i]){
      cnt++;
    }
    else cnt = 1;
    mx = max(cnt, mx);
  }
  cout << "\nMAX increasing subsequence: " << mx << endl;
  // Find median of S
  // Use sorted array
  cout << "Found median: ";
  if (n % 2 == 0){
    cout << (a[(n - 1) / 2] + a[(n) / 2]) / 2;
  }
  else cout << a[n / 2];
  cout << endl;

  // Find an item that appears > n / 2 times in the array
  cout << "Item that appears in more than n / 2 occassions" << endl;
  mx = -1;
  cnt = 1;
  found = 0;
  for (int i = 1; i < n && !found; i++){
    if (a[i] == a[i - 1]) cnt++;
    else cnt = 1;
    mx = max(mx, cnt);
    if (mx > n / 2){
      cout << a[i];
      found = 1;
    }
  }
  cout << (!found ? "Not found such item": "") << endl;
  
}

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
