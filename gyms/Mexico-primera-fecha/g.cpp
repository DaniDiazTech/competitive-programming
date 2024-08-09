// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) cin >> x;
  sort(a.begin(), a.end());
  int c = 0;
  bool f = 0;
  for (int i =0 ;i < n; i++){
    if (i> 0 && a[i] == a[i - 1]) continue;
    if (a[i]- c > 1 || i == n - 1){
      break;
    }
    c = a[i];
    f = !f;
  }
  string b[2] = {"Alicius", "Bobius"};
  cout << b[f] << endl;
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
