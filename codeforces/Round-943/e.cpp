// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;

  cout << "1 1\n1 2\n";
  if (n == 2){
  }
  else if (n == 3){
    cout << "3 3\n";
  }
  else{
    cout << "4 2\n";
    for (int j = 4; j <= n; j++){
      cout << j << " " << j << '\n';
    }
  }
  cout << '\n';
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
