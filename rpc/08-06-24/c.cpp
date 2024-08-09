// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, t;
  cin >> n >> t;
  t--;
  if (t == 0){
    cout << n << endl;
    return;
  }
  int cnt = 0; 
  
  for (int i = 1; i * i <= t; i++){
    if (t % i == 0){
      if (i <= n) cnt++;
      if ((t / i) <= n && (i * i != t)) cnt++;
    }
  }
  cout << cnt << endl;
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
