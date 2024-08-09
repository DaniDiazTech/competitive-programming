// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int L, W, H;
  vector<int> a(3);
  cin >> L >> W >> H >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  int ans = 0;
  do{
    ans = max(ans, (L / a[0]) * (W/ a[1]) * (H/ a[2]));
  }
  while (next_permutation(a.begin(), a.end()));
  cout << ans << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
