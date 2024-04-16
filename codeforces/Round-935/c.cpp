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
  s = '$' + s + '$'; 
  // right
  vector<int> p(n + 2);
  for (int i = n; i>= 1; i--){
    p[i] = p[i + 1];
    p[i] += s[i] == '1';
  }
  int ans = -1; 
  int b = 0;
  // middle element
  for (int i = 0; i <= n; i++){
    b += s[i] == '0';
    if (2 * b >= i && 2 * p[i + 1] >= n - i){
      if (ans == -1){
        ans = i;
        continue;
      }
      // can select
      double m = n / 2.0;
      double x = abs(m - 1.0 * ans);
      double y = abs(m - 1.0 * i);
      // cout << i << " " << x << " " << y << endl;
      if (x > y){
        ans = i; 
      }
    }

  }

  cout << ans << '\n';
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
