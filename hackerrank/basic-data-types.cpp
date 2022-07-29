/*
Problem name: 
Algorithm or Logic:
Complexity: 
Link: y
More info: 
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'

// Solution
void solve(){
  int n;
  long m;
  char ch;
  float fl;
  double dl;

  scanf("%d %ld %c %f %lf", &n, &m, &ch, &fl, &dl);
  printf("%d\n%ld\n%c\n%.3f\n%.9lf", n, m, ch, fl, dl);
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
