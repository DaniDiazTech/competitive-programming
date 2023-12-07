// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

// L R U D
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};


int c[8][8];

void solve(){
  string s; cin >> s;
  // NUMBER
  for (int i = 0 ; i < 8; i++){
    string x;
    x += s[0] ;
    x += char('1' + i);
    
    if (x != s) cout << x << '\n';
  }
  for (int i = 0 ; i < 8; i++){
    string x;
    x += char('a' + i);
    x += s[1];
    if (x != s) cout << x << '\n';
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
