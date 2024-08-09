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
  for (auto &c: a) cin >> c;
  sort(a.begin(), a.end());
  bool f = 1;
  int j = 1;
  for (int i = 1; i < n; i++){
    if (a[i] % a[0] != 0){
      j = i;
      break;
    } 
  }
  for (int i = 0;i < n; i++){
    if (a[i] % a[0] == 0 || a[i] % a[j]  == 0) continue;
    f = 0;
    break;
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
