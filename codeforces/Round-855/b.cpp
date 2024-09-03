// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  string s; cin >> s;
  vector<int> a(26);
  vector<int> b(26);

  // cout << (int)('a') << " " << (int)('A') << endl;
  for (int i =0 ; i < n; i++){
    int x= (int)s[i];
    if (x >= 97){
      // lowercase
      a[s[i] - 'a']++;
    }
    else{
      b[s[i] - 'A']++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++){
    ans += min(a[i], b[i]);
    int x = max(a[i], b[i]) - min(a[i], b[i]);
    int l = x / 2;
    while (k && l){
      k--;
      l--;
      ans++;
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
