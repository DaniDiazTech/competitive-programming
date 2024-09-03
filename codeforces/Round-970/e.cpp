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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++){
    a[i] = s[i - 1]  - 'a';
  }
  vector<vector<int>> even(n + 1, vector<int>(26)), odd(n + 1, vector<int>(26));

  for (int i =1;i <= n; i++){
    for (int j = 0; j < 26; j++){
      even[i][j] += even[i - 1][j];
      odd[i][j] += odd[i - 1][j];

      if (i % 2 == 0){
        if (j == a[i]) even[i][j]++;
      }
      else{
        if (j == a[i]) odd[i][j]++;
      }
    }
  }


  if (n % 2 == 0){
    int e = *max_element(even[n].begin(), even[n].end());
    int o = *max_element(odd[n].begin(), odd[n].end());
    cout << n - e - o << endl;
  }
  else{
    int ans = n; 
    for (int i = 1; i <= n; i++){
      vector<int> o(26), e(26);
      
      for (int j =0;j < 26; j++){
        o[j] += odd[i - 1][j];
        e[j] += even[i - 1][j];

        o[j] += even[n][j] - even[i][j];
        e[j] += odd[n][j] - odd[i][j];
      }
      
      int x = *max_element(o.begin(), o.end());
      int y = *max_element(e.begin(), e.end());
      ans = min(ans, n - x - y);
    }
    cout << ans << endl;
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
