// B. All distinct
// Accepted
// https://codeforces.com/contest/1692/problem/B

#include <bits/stdc++.h>

using namespace std;

// Solution
void solve(){
  int n;
  cin >> n;

  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++){
    int x; 
    cin >> x;
    mp[x]++;
  } 

  int even, counter;
  even = counter = 0;

  // Access the element
  for (auto const& pair: mp){
    if (pair.second % 2){
      counter++;
    } 
    else{
      even++;
    }
  }

  if (even % 2 == 0){
    counter += even;
  }
  else{
    counter += even - 1;
  }

  cout << counter << endl;
}

int main() {

  // Only local. Comment out if the online judge doesn't use the flag
  #ifndef ONLINE_JUDGE
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  int t;
  cin >> t;


  for (int i = 0; i < t; i++) solve();

  return 0;
}
