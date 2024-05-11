// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  string v = "aeiou";
  string f = "", s = "";

  char vowel = 'o';
  int v1 = -1, v2 = -1;

  for (int i = 0;i < n; i++){
    if (i != 0){
      bool is = 0;
      for (auto x: v){
        is |= x == a[i];
      }
      if (is){
        v1 = i;
        break;
      }
      else{
        f += a[i];
      }
    }
    else{
      f += a[i];
    }
  }
  
  for (int i = m - 1;i >= 0; i--){

    if (i != m - 1){
      bool is = 0;
      for (auto x: v){
        is |= x == b[i];
      }
      if (is){
        v2 = i;
        break;
      }
      else{
        s += b[i];
      }
    }
    else{
      s += b[i];
    }
  }

  if (v2 != -1){
    vowel = b[v2];
  }
  else if (v1 != -1){
    vowel = a[v1];
  }

  string ans = f;
  ans += vowel;
  reverse(s.begin(), s.end());
  ans += s;
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
