// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, x, y;
  cin >> n >> x >> y;
  x--;y--;
  vector<int> a(n);
  for (int i = y; i <= x; i++){
    a[i] = 1;
  }
  int m = -1;
  for (int i = y - 1; i >= 0; i--){
    a[i] = m;
    m = -m;
  }
  m = -1;
  for (int i = x + 1; i < n; i++){
    a[i] = m;
    m = -m;
  }
  for (auto x: a) cout << x << " ";
  cout  << endl;
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
