// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s;
  while(cin >> s){
    s.push_back('X');
    int n = s.size();
    int cnt = 0;
    bool first = 1;
    int i = 0;
    int mx = 0;
    while (i < n){
      if (s[i] != 'X'){
        cnt++;
      }
      else{
        mx = max(mx, (cnt - 1) / 2);
        cnt = 0;
      }
      i++;
    }

    i = 0;
    mx = max(cnt, mx);
    while (i < n && s[i] != 'X'){
      cnt++;
      i++;
    }
    mx = max(cnt -1, mx);

    cnt = 0; i = n - 2;
    while (i >= 0 && s[i] != 'X'){
      cnt++;
      i--;
    }
    mx = max(cnt - 1, mx);
    
    cout << mx << '\n';
  }
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
