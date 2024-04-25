// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> ans(n, 1);
  // key -> gcd
  // value -> max size with gcd = key
  vector<map<int,int>> v(n + 1);

  for (int i =0;i <= n; i++){
    v[i][0] = 0;
  }

  for (int i = 1;i <= n; i++){
    int x; cin >> x;
    for (auto l: v[i - 1]){
      int g = gcd(l.first, x);
      int sz = max(v[i][g], l.second + 1);
      v[i][g] = sz;
      ans[l.second] = max(ans[l.second], g);
    }
  }

  for (auto x: ans) cout << x << ' ';
  cout << '\n';
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
