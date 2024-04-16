// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  map<int,int> mp;
  int s = 0;
  for (int i =0;i < n; i++){
    int x; cin >> x;
    x %= 3;
    mp[x]++;
    s = (s + x) % 3;
  }

  s %= 3;

  if (s == 0){
    cout << 0;
  }
  else if (s == 1){
    if (mp[1]){
      cout << 1;
    }
    else cout << 2;
  }
  else{
    cout << 1;
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
