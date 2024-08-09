// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0;i < n; i++) cin >> a[i];

  int ans = 0;
  for (int i = 0;i < n; i++){
    if (a[i] == 0) continue;

    if (i < n - 1 && a[i] <= 2 && a[i + 1] <= 2){
      ans++;
      i++;
    }
    else ans++;
  }
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
