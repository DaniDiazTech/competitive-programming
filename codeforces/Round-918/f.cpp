// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  for (auto &c: a) cin >> c.first >> c.second;
  sort(a.begin(), a.end(), [&](pair<int,int> &i, pair<int,int> &j){
    return i.second < j.second;
  });
  
  ordered_set s;
  ll ans = 0;
  for (int i =0; i < n; i++){
    int x = s.order_of_key(a[i].first);
    ans += s.size() - x;
    s.insert(a[i].first);
  }
  cout << ans << '\n';
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
