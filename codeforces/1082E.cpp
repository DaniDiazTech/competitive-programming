// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, c;
  cin >> n >> c;
  vector<int> f(500005);
  int mx = 0, cnt = 0;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    if (x == c) cnt++;
    else f[x] = max(cnt, f[x]) + 1;
    mx = max(f[x] - cnt, mx);
  }
  cout << mx + cnt << endl;
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