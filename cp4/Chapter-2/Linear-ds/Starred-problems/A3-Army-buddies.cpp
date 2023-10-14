// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int s, b;
  while(cin >> s >> b && s > 0 && b > 0 ){
    // prev, next
    vector<pair<int, int>> v;
    // 0 = * = n +1
    v.push_back({-1, 1});

    for (int  i = 1; i <= s + 1; i++){
      v.push_back({i - 1, i + 1});
    }

    for (int i =0 ;i < b; i++){
      int l, r; cin >> l >> r;
      int x = v[l].first;
      int y = v[r].second;

      // update
      v[x].second = y; 
      v[y].first = x; 
      cout << (x == 0 ? "*" : to_string(x)) << " " << (y == s + 1 ? "*" : to_string(y));
      cout << '\n';
    }
    cout << "-\n";
  }
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
