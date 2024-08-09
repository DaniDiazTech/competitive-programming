// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, s, m;
  cin >> n >> s >> m;
  bool f = 0;
  int a[n + 2];
  int b[n + 2];
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  a[0] = b[0] = 0;
  a[n+ 1] = b[n + 1] = m;

  for (int i = 1; i <= n + 1; i++){
    f |= (a[i] - b[i - 1]) >= s;
  } 

  cout << (f ? yes: no) << endl;
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
