// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a) cin >> c;
  bool f = 0;
  for (int i = 0;i < n; i++){
    bool b = 1;
    for (int j = 0; j < n - 1; j++){
      if (a[(i + j + 1) % n] < a[(i + j) % n]){
        b = 0; 
      }
    }
    if (b){
      f = 1;
      break;
    }
  }
  cout << (f ? yes: no) << endl;
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
