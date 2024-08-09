// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  int a[n], b[m];

  for (int i =0 ;i < n; i++) cin >> a[i];
  for (int j =0 ;j < m; j++) cin >> b[j];

  int s = 0;
  for (int i = 0;i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i] + b[j] <= k){
        s++;
      }
    }
  }
  cout << s << endl;
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
