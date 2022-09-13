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
// #define endl '\n'
#define int long long int
#define double long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN

int ask(int l, int r){
  if (l == r) return -1;
  cout << "? " << l << " " << r << endl;
  int x;
  cin >> x;
  return x;
}

// Solution
void solve(){
  int n;
  cin >> n;

  int l = 1, r = n;

  while (r > l){
    int mid = (r + l) >> 1;

    int fq = ask(l, r);

    if (fq <= mid){
      int sq = ask(l, mid);
      if (fq == sq){
        // Share region
        r = mid;
      }
      else{
        // Not share region
        l = mid + 1;
      }
    }
    else{
      // Second greatest to the right
      int sq = ask(mid + 1, r);
      if (sq == fq){
        // Share region
        l = mid + 1;
      } 
      else{
        // Not share region
        r = mid;
      }
    }
  }

  cout << "! " << l << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local using my exc command.
  // #if LOCAL
  //     // For getting input from input.txt file
  //   freopen("input.txt", "r", stdin);

  //   // Printing the Output to output.txt file
  //   freopen("output.txt", "w", stdout);
  // #endif

  // Testscases
  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
