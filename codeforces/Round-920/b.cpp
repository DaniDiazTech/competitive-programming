// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string a, b; cin >> a >> b;
  int m = 0, d = 0;
  for (int i = 0;i < n; i++){
    m += a[i] == '1' && b[i] == '0';
    d += a[i] == '0' && b[i] == '1';
  }
  cout << max(m, d) << '\n';

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
