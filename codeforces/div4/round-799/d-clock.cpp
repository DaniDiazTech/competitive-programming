// D. The clock
//  Not accepted
// https://codeforces.com/contest/1692/problem/D

#include <bits/stdc++.h>

using namespace std;


bool is_palindrome(string hh, string mm){
  string rmm = mm;
  reverse(rmm.begin(), rmm.end());

  if (rmm == hh) return 1;
  return 0;
}

// Solution
void solve(){
  int hh, mm, s;
  char aux; 
  cin >> hh >> aux >> mm >> s;


}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local. Comment out if the online judge doesn't use the flag
  #ifndef ONLINE_JUDGE
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
