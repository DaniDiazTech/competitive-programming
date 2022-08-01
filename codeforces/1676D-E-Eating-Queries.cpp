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
#define MAX LLONG_MAX
#define MIN LLONG_MIN

int bs(vector<int> &arr, int query){
  int l = 0, r = arr.size() - 1;  
  while (l <= r){
    int mid = (r + l) / 2; 

    if (arr[mid] >= query){
      r = mid - 1;
    }
    else{
      l = mid + 1;      
    }
  }
  return l;
}

// Solution
void solve(){
  int n, q;
  cin >> n >> q;

  vector<int> arr;

  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  sort(arr.rbegin(), arr.rend());

  for (int i = 0; i < n; i++){
    if (i == 0) continue;
    arr[i] = arr[i - 1] + arr[i];
  }
  
  for (int i = 0; i < q; i++){
    int query;
    cin >> query;

    if (query > arr[n - 1]){
      cout << -1 << endl;
      continue;
    }

    int ans = bs(arr, query) + 1;
    cout << ans << endl;
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
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
