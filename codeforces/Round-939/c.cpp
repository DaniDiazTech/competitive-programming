// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string p = "";
  for (int i = 1; i<= n; i++) p += to_string(i) + " ";
  int ans = ( (n * (n + 1) * (2 *n + 1)) / 3) - ((n * (n + 1)) / 2); 
  cout << ans << " " << 2 * n << endl;
  for (int i = n; i >= 1; i--){
    cout << "1 " << i << " " << p << '\n';
    cout << "2 " << i << " " << p << '\n';
  }
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
    solve();
  }
}
