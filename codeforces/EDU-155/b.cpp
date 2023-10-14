// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n], b[n];
  int mna = 1e9+100;
  int mnb = mna;
  int ans= 0, ans2 = 0;

  for (int i = 0;i < n; i++){
    cin >> a[i];
    mna = min(a[i],mna);
  }

  for (int i =0; i < n;i++){
    cin >> b[i];
    mnb = min(b[i], mnb);
    ans += b[i] + mna;
  }

  for (int i =0; i < n; i++){
    ans2 += a[i] + mnb;
  }
  cout << min(ans2, ans) << endl;
}

int32_t main() {
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
