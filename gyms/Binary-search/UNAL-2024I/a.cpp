// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, q;
  cin >> n >> q;
  int a[n];
  for (int i = 0;i < n; i++) cin >> a[i];
  while(q--){
    int x; cin >> x;
    int s = lower_bound(a, a + n, x) - a;
    if (s == n){
      cout << -1;
    }
    else{
      cout << (a[s]== x ? s : -1);
    }
    cout << '\n';
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
