// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  int h[n][m];
  for (int i = 0;i < n; i++){
    for (int j = 0;j < m; j++){
      char ch; cin >> ch;
      if (ch == '*'){
        h[i][j] = 0;
      }
      else{
        h[i][j] = (i == 0 ? 1 : h[i - 1][j] + 1);
      }
    }
  }



  int ans = 0;

  for (int i =0 ;i < n; i++){
    stack<int> s;
    int best = 0;
    for (int j =0; j< m; j++){
      while (s.size() && h[i][j] <= h[i][s.top()]){
        int height = h[i][s.top()];
        s.pop();
        int l = s.size() ? s.top() : -1;
        best = max(best, (height) * (j - 1 - l));
      }
      s.push(j);
    }
    
    while (s.size() && 0 <= h[i][s.top()]){
        int height = h[i][s.top()];
        s.pop();
        int l = s.size() ? s.top() : -1;
        best = max(best, (height) * (m - 1 - l));
    }

    ans = max(ans, best);
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
