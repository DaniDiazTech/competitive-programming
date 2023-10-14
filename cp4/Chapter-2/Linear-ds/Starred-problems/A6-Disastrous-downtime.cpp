// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i =0;i < n; i++){
    cin >> a[i];
  }

  a[n] = 1e9;

  int l = 0, r = 0; 
  int mx = 0;

  while (r <= n){
    if (a[r] - a[l] >= 1000){
      // different
      l++;
    }
    else{
      mx = max(mx, r - l + 1);
      r++;
    }
  }

  // ceiling
  cout << (mx + k - 1) / k << endl;
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
