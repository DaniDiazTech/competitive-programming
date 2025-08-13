// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i =0 ;i < n; i++){
    cin >> a[i];
  }
  for (int i =0 ;i < n; i++){
    cin >> b[i];
  }
  int l = 0, r=  0;
  for (int i =0 ;i < n; i++){
    int diff = a[i] - b[i];
    if (diff > 0){
      l+=diff;
    }
    else r-=diff;
  }

  int ans = l + 1;

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
