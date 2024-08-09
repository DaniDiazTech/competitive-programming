// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  int i = 0, j = 0;

  int c = 0;

  while ( i < n && j < m){
    if (s[i] == t[j]){
      c++;
      i++;
      j++;
    }
    else if (s[i] == '?'){
      c++;
      s[i] = t[j];
      i++;
      j++;
    }
    else i++;
  }

  while (i < n){
    if (s[i] == '?') s[i] = 'a';
    i++;
  }

  if (c == m){
    cout << yes << endl;
    cout << s << endl;
  }  
  else cout << no << endl;
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
