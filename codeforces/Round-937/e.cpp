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
  set<int> v;

  for (int i = 1; i * i <= n; i++){
    if (n % i == 0){
      v.insert(i);
      v.insert(n / i);
    }
  }
  
  for (auto d: v){
    int x  = n / d;
    // hashing
    vector<vector<int>> mp(d, vector<int>(26, 0));
    for (int i = 0;i < n; i++){
      mp[i % d][s[i] - 'a']++;
    }
    int cnt = 0;
    for (int i =0 ;i < d; i++){
      int mx = 0;
      for (int j =0 ; j < 26; j++){
        mx =max(mx, mp[i][j]);
      }
      cnt += x - mx;
    }

    if (cnt <= 1){
      cout << d << '\n';
      return;
    }
  }
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
