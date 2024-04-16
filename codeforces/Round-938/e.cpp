// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string s; cin >> s;
  vector<int> a(n);
  for (int i = 0;i < n; i++){
    if (s[i] == '1') a[i] = 1;
  }
  int ans = 1;
  // Select k
  for (int k = n; k >= 2; k--){
    vector<int> inv(n);
    int sum = 0;

    bool f= 1;    
    // Left
    for (int j =0 ; j < n; j++){
      if (j > 0) inv[j] = inv[j - 1];

      int x = sum - (j >= k ? inv[j - k] : 0) + a[j];
      if (j + k > n){
        // Can check backwards
        if (x % 2 == 0){
          f = 0;
          break;
        }
      }
      else{
        if (x % 2 == 0){
          // inversion
          sum++;
          inv[j]++;
        }
      }
    }

    if (f){
      ans = k;
      break;
    }

    // Right
    f = 1;
    sum =0;
    vector<int> b(n);
    for (int i = 0; i < n; i++){
      inv[i] = 0;
      b[i] = a[n - i - 1];
    }
    for (int j =0 ; j < n; j++){
      if (j > 0) inv[j] = inv[j - 1];
      int x = sum - (j >= k ? inv[j - k] : 0) + b[j];
      if (j + k > n){
        // Can check backwards
        if (x % 2 == 0){
          f = 0;
          break;
        }
      }
      else{
        if (x % 2 == 0){
          // inversion
          sum++;
          inv[j]++;
        }
      }
    }

    if (f){
      ans = k;
      break;
    }
  }

  cout << ans << endl;
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
