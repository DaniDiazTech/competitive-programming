// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int a[3];
  for (int i =0 ;i < 3; i++) cin >> a[i];
  sort(a, a + 3);
  int on = 3;
  bool f = 0;
  for (int i =1 ;i < 3; i++){
    while (a[i] != a[0] && on > 0){
      a[i] -= a[0];
      on--;
    }
  }
  if (a[1] == a[2] && a[2] == a[0]) f = 1;

  cout << (f ? yes : no) << '\n';
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
