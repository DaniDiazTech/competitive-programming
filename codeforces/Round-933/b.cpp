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
  for (int i =0;i < n; i++ ) cin >> a[i];
  bool f = 1;
  for (int i = 0;i < n - 2; i++){
    if (a[i] < 0){
      f = 0;
      break;
    } 

    a[i+ 1] -= 2 * a[i];
    a[i + 2] -= a[i];
  }
  f &= (a[n - 1] == 0) && (a[n - 2]  == 0);
  cout << (f ? yes: no ) << endl;
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
