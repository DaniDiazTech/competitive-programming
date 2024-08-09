// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int n = s.size();
  map<char, char> mp;
  mp = {
    {'0', '0'},
    {'1', '1'},
    {'2', '2'},
    {'3', 'E'},
    {'5', '5'},
    {'6', '9'},
    {'8', '8'},
    {'9', '6'},
    {'E', '3'}
  };
  auto in = mp;
  int ans = 0;
  for (int i = 0 ;i <= n / 2; i++){
    if (i > n - i - 1) break;
    if (mp[s[i]] == s[n - i - 1]) continue;
    else if (in.count(s[i]) || in.count(s[n - i - 1])) ans++;
    else ans+=2;
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
