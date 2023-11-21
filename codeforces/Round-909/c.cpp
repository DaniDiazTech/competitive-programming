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
  for (int i = 0;i < n; i++){
    cin >> a[i];
  }

  // do kadanes
  int mx = a[0];
  int i = 0, j = 0;
  while (j < n){
    if (j + 1 < n && (a[j] & 1) != (a[j + 1] & 1)){
      // alterating keep going
      j++;
    }
    else{
      // cout << i << " " << j << endl;
      // Next stop becomes alternating
      // calculate kadanes
      int ml = -1e7;
      int cur = ml;
      for (int k = i; k <= j; k++){
        cur = max(a[k], a[k] + cur);
        ml = max(cur, ml);
      }
      mx = max(mx, ml);
      j++;
      i= j;
    }
  }
  cout <<mx << endl;
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
