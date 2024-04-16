// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i =0 ;i < n; i++){
    for (int j = 0;j < m; j++){
      cin >> a[i][j];
    }
  }
  string ans = "";
  for (int j =0 ; j < m; j++){
    vector<int> mp(26);
    for (int i =0 ;i < n; i++){
      mp[a[i][j] - 'a']++; 
    }
    int mx = 0;
    char ch = 'a';
    for (int i =0 ;i < 26; i++){
      if (mx < mp[i]){
        mx = mp[i];
        ch = 'a' + i;
      }
    }

    ans += ch;
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
