// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n];
  int b[n];
  for (int i = 0;i < n; i++) cin >> a[i];
  for (int i = 0;i < n; i++) cin >> b[i];
  bool f = 1;

  multiset<pair<int,int>> A, B;

  for (int i = 0;i < n / 2; i++){
    A.insert({min(a[i], a[n - 1 - i]), max(a[i], a[n -  1 - i])});
    B.insert({min(b[i], b[n - 1 - i]), max(b[i], b[n -  1 - i])});
  }
  if (n & 1){
    A.insert({-1, a[n / 2]});
    B.insert({-1, b[n / 2]});
  }

  // cout << "A:\n";
  // for (auto x: A){
  //   cout << x.first << " " << x.second << endl;
  // }
  // cout << endl;

  // cout << "B:\n";
  // for (auto x: B){
  //   cout << x.first << " " << x.second << endl;
  // }

  for (auto x: A){
    if (B.count(x)){
      auto it = B.find(x); 
      B.erase(it);
    }
    else f = 0;
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
