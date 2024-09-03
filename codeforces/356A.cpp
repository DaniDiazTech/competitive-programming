// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, q;
  cin >> n >> q;
  set<int> alive;

  for (int i =0 ;i < n; i++) alive.insert(i);
  vector<int> ans(n, - 1);
  for (int i = 0;i < q; i++){
    int l, r, x; cin >> l >> r >> x;
    l--;r--;x--;

    auto it = alive.lower_bound(l); 
    vector<int> f;
    while (it != alive.end()){
      int cur = *it;
      if (cur > r) break;
      if (cur != x){
        f.push_back(cur);
        ans[cur] = x;
      }
      it++;
    } 

    for (auto x: f){
      alive.erase(x);
    }
  }

  for (int i =0;i < n; i++){
    cout << ans[i] + 1<< ' ';
  }
  cout << endl;
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
