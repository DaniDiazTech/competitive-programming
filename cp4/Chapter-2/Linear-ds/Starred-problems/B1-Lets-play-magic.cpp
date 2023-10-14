// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  bool f= 0;
  while (cin >> n){
    if (n == 0) break;
    vector<string>a(n);
    int cur=0;
    for (int i = 0 ; i < n; i++){
      string key, l;
      cin >> key >> l;
      int x = l.size();
      int cnt = 1;
      while (cnt < x){
        if (a[cur].empty()){
          cnt++;
        }
        cur = (cur + 1) % n;
      }
      while (!a[cur].empty()){
        cur = (cur + 1) % n;
      }
      a[cur] = key;
      cur = (cur + 1) % n;
    }
    for (int i= 0;i < n; i++){
      if (i > 0) cout << ' ';
      cout << a[i];
    }
    cout << '\n';
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
