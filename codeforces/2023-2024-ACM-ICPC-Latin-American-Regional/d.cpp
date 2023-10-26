// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string a[n];
  for (int i =0 ;i < n; i++){
    cin >> a[i];
  }
  string ans = a[0];
  set<char> s;
  for (auto x : ans) s.insert(x);

  int q; cin >> q;
  while ( q--){
    string pat; cin >> pat;    
    int cnt = 0;

    for (int i =0 ;i <n; i++){
      bool ok = 1;
      for (int k =0 ;k < 5; k++){
        char x= pat[k];
        if (x == 'X'){
          ok &= s.count(a[i][k]) == 0;
        }
        else if ( x == '!'){
          ok &= s.count(a[i][k]) > 0 && a[i][k] != ans[k];
        }
        else{
          ok &= a[i][k] == ans[k];
        }
      }
      cnt += ok;
    }

    cout << cnt << endl;
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
