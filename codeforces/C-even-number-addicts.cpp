// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int e = 0, o = 0;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    x = abs(x);
    o += x % 2;
    e += x % 2 == 0;
  }
  e = e % 2;
  o = o % 4;
  if (o == 0 || o == 3 || (o == 1 && e == 1)){
    cout << "Alice";
  }
  else cout << "Bob";
  cout << '\n';
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
