// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> a(n + 1), p(n + 1);
  for (int i= 1; i <= n; i++){
    int x; cin >> x;
    a[i] =x ;
    p[i] = x ^ p[i - 1];
  }
  string s; cin >> s;
  int cur1, cur0;
  cur1 = cur0 = 0;
  for (int i= 1; i <= n; i++){
    if (s[i - 1] == '1'){
      cur1 ^= a[i];
    }
    else{
      cur0 ^= a[i];
    }
  }
  int q; cin >> q;
  while (q--){
    int type; cin >> type;
    if (type == 1){
      int l, r; cin >> l >> r;
      cur1 ^= p[r] ^ p[l - 1];
      cur0 ^= p[r] ^ p[l - 1];
    }
    else{
      bool num; cin >> num;
      cout << (num ? cur1 : cur0) << ' ';
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
