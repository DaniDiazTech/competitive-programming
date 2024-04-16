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

  int l = 1, r = n - 2;

  while (l < n && a[l] == a[0]){
    l++;
  }

  while (r >= 0 && a[r] == a[n - 1]){
    r--;
  }
  if (l > r){
    cout << -1;
  }
  else{
    int x = min(l, n - r - 1);
    int prev = -1;
    int y = n + 1;
    for (int i = 0;i < n; i++){
      if (a[i] != a[0]){
        if (prev != -1){
          y = min(y, i - prev - 1);
        }
        prev = i;
      }
    }
    cout << min(x, y);
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
