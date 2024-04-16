// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n + 1];
  a[0] = -1;
  for (int i = 0;i < n; i++) cin >> a[i + 1];
  sort(a, a + n + 1);

  int x = a[(n + 1) / 2];
  int cnt  = 0;

  for (int i = (n + 1) / 2; i <= n; i++){
    if (a[i] ==x) cnt++;
  }
  cout << cnt << endl;
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
