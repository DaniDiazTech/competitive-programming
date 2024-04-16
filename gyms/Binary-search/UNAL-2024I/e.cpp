// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


int q(int l, int r){
  cout << "? " << l << " " << r << endl;
  int ans; cin >> ans;
  return ans;
}

void solve(){
  int n;
  cin >> n;
  int l = 1, r = n;
  int smax = q(l, r);
  
  // max right of smax
  if (smax == 1 || smax != q(1, smax)){
    l = smax;
    while (l + 1 < r){
      int m = ( l + r )/ 2;

      if (q(smax, m) == smax){
        // max in this range
        r = m;
      }
      else{
        l = m;
      }
    }

    cout << "! " << r << endl;
  }
  else{
    r = smax;
    // to right
    while (l + 1 < r){
      int m = (l + r) / 2;
      if (q(m, smax) == smax){
        // max in this range
        l = m;
      }
      else{
        r = m;
      }
    }
    
    cout << "! " << l << endl;

  }

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
