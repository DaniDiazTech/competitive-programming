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
  int mx = 0;
  for (int i =0 ;i < n; i++){
    bool f = ((i > 0 && a[i - 1] >= a[i]) || (i < n -1 && a[i + 1] >= a[i]));
    bool w = (i - 2 >= 0 && a[i - 2] >= a[i]) || (i < n - 2 && a[i + 2] >= a[i]) ;
    if (f || w){
      mx = max(mx, a[i]);
    }
  }
  cout << mx << endl;
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
