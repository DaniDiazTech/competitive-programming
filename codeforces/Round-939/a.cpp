// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, q; cin >> n >> q;
  int a[n];
  for (int i = 0;i < n; i++){
    cin >> a[i];
  }  
  while (q--){
    int l; cin >> l;
    cout << min(l, a[0] - 1) << " ";
  }
  cout << endl;
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