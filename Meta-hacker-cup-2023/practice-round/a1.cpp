// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int s, d ,k;
  cin >>s >> d >> k;
  // k + 1 buns
  int buns = 2 *  (s + d);
  int other = s + 2 *d;
  bool f = 1;
  f &= buns >= k + 1;
  f &= other >= k;
  cout << (f ? yes : no) << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    cout << "Case #" << t << ": ";
    solve();
  }
}
