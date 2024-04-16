// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int n = s.size(); 
  int mx = 0;
  for (int d = 1; d <= n; d++){
    int cnt = 0, mxc = 0;
    for (int i = 0; i + d < n; i++){
      if (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') cnt++;
      else cnt = 0;
      mxc = max(mxc, cnt);
    }
    if (mxc >= d){
      mx = max(mx, 2 * d);
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
