// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int a, b, c; cin >> a >> b >> c;
  int k = a;
  while (a){
    if (c > b){
      c--;
    }
    else if (c == b){
      b--;
    }
    a--;
  }

  if (b % 2 == c % 2){
    cout << k + b << endl;
  } 
  else{
    cout << -1 << endl;
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
