// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;

  vector<int> minn, maxx;

  for (int i = 0;i < n; i++){
    int l; cin >> l;
    int mn = 1e9, mx = -1;
    for (int j = 0; j < l; j++){
      int x; cin >> x;
      if (x > mn){
        mn = -1;
        mx = 1e9;
        continue;
      }
      mn = min(x, mn);
      mx = max(x, mx);
    }
    minn.push_back(mn);
    maxx.push_back(mx);
  }
  maxx.push_back((int)1e9);
  sort(maxx.begin(), maxx.end());

  ll ans = 0;
  for (int i =0 ;i < n; i++){
    int l = -1, r = n;
    while (l + 1 < r){
      int m = (l + r) / 2;
      if (maxx[m] > minn[i]) r = m;
      else l = m;
    }
    ans += n - r;
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
