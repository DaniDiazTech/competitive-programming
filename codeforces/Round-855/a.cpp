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

  string f = "$";
  for (int i =0 ;i < n; i++){
    char ch = s[i];
    if (ch == 'M') ch = 'm';
    if (ch == 'E') ch = 'e';
    if (ch == 'O') ch = 'o';
    if (ch == 'W') ch = 'w';
    if (f.back() != ch) f.push_back(ch);
  }

  cout << (f == "$meow" ? yes: no) << endl;
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
