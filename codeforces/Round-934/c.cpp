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

  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    a[x]++;
  }

  set<int> c;
  bool alice = 1;
  for (int i =0 ;i < n; i++){
    if (a[i] == 1){
      if (alice){
        c.insert(i);
        alice = 0;
      }
      else{
        alice = 1;
      }
    }
  }
  // Picked all the ones

  for (int i = 0;i < n; i++){
    if (a[i] >= 2){
      c.insert(i);
    }
  }

  int ans = n;
  for (int i = 0; i < n; i++){
    if (c.count(i) == 0){
      ans = i;
      break;
    }
  }

  cout << ans << '\n';
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
