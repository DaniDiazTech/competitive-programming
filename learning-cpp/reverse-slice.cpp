#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'

// Solution
void solve(){
  vector<int> v = {1, 2, 3, 4, 5 ,6, 7};
  vector<int> vslice;

  int x = 3, y = 6;

  for (int i = x; i <= y; i++) vslice.push_back(v[i]);

  reverse(vslice.begin(), vslice.end());

  for (auto i : vslice) cout << i << " ";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  

  // Testscases
  int tc = 1;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
