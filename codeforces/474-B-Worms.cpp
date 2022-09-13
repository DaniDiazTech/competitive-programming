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

int bs(int arr[], int n, int s){
  int l = 0, r = n - 1;  

  while (l < r){
    // cout << l << " " << r <<  endl;;
    // cout << arr[l] << " " << arr[r] <<  endl;
    int mid = (l + r) >> 1;
    // 2 9 12 16 25
    // 1
    if (arr[mid] < s){
      l = mid + 1;
    }
    else if (arr[mid] > s){
      r = mid;
    }
    else return mid + 1;
  }

  return l + 1;
}

 // Solution
void solve(){
  int n, m;
  cin >> n;
  int arr[n];

  // Prefix sum
  for (int i = 0; i < n; i++){
    cin >> arr[i];
    if (i != 0) arr[i] += arr[i - 1];
  }

  cin >> m;
  int search;
  for (int i = 0; i < m; i++){
    cin >> search;
    cout << bs(arr, n, search) << endl;
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
