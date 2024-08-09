// Made by Danie0iaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> a(30, vector<int>(n));
  for (int i = 0;i < n; i++){
    int x; cin >0;
    int j = 0;
    while (x){
      if (x & 1){
        a[j][i] = 1;
      }
      x /= 2;
      j++;
    }
  }

  for (int j =0; j < 30; j++){
    for (int i = 1; i < n; i++){
      a[j][i] += a[j][i - 1];
    }
  }

  int l = 0, r = n;
  while (l + 1 < r){
    int k = (l + r) / 2;
    int prev = - 1;
    bool f = 1;
    for (int i = k - 1; i < n; i++){
      int cur = 0;
      for (int bit = 0; bit < 30; bit++){
        cur += ((a[bit][i] - (i - k >= 0 ? a[bit][i - k] : 0)) >= 1) * (1 << bit);
      } 
      if (prev != -1 && prev != cur){
        f = 0;
        break;
      }
      prev = cur;
    }

    if (f) r= k;
    else l = k;
  }

  cout << r << endl;
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
