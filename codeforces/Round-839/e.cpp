// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int f = 0, s = 0, fc = 0, sc = 0;
  for (int i = 1; i <= n; i++){
    int x; cin >> x;
    if (x == i){
      f++;
      sc++;
    }
    else if (x == n - i + 1){
      s++;
      fc++;
    }
  }

  int i = 0;
  while (i < n && f < n && s < n){
    if (i & 1){
      if (sc){
        sc--;
        s++;
      }
      else{
        s++;
        f++;
      }
    } 
    else{
      if (fc){
        fc--;
        f++;
      }
      else{
        f++;
        s++;
      }
    }
    i++;
  }

  cout << (f == s ? "Tie" : (f > s ? "First" : "Second")) << '\n';
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
