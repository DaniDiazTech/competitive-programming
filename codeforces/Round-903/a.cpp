// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  string x, s; cin >> x >> s;

  int op = 0;
  bool f =0 ;
  string cur =  x; 

  while (cur.size() <= 26 * s.size() && !f){
    // cout << "CUR: " << cur << endl;
    if (cur.size() < s.size()){
      cur = cur + cur;
      op++;
      continue;
    }

    for (int i = 0; i <= cur.size() - s.size(); i++){
      bool l = 1;

      for (int j = 0; j < s.size(); j++){
        if ( cur[j + i] != s[j]){
          l = 0;
          break;
        }
      }

      if (l){
        f = l;
        break;
      }

    }
    if (f) break;
    op++;
    cur = cur + cur;
  }
  cout << (f ? op : -1 ) << '\n';
  
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
