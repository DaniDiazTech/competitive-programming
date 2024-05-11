// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

bool f = 0;
void solve(){
  int n;
  cin >> n;
  map<int,int> mp;
  // Different
  // vector<int> a(n);
  // set<vector<int>> v;
  // for (int i = 0;i < n; i++) cin >> a[i];
  // for (int i = 0;i < n ; i++){
  //   for (int j =i + 1; j < n; j++){
  //     auto b = a;
  //     swap(b[i], b[j]);
  //     v.insert(b);
  //   }
  // }

  // for (auto x: v){
  //   for (auto c: x) cout << c << " ";
  //   cout << endl;
  // }
  // cout << v.size() << endl;
  ll ans = 0;
  bool f= 0;
  for (int i = 0;i < n; i++){
    int x; cin >> x;
    if (mp[x]) f= 1;
    ans += i - mp[x];
    mp[x]++;
  }
  ans += (f ? 1: 0);
  cout << ans << endl;
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
