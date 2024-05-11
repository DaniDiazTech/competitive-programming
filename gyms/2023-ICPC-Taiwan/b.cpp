// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int rt, rj;
  double st, sj;

  cin >> rt >> rj >> st >> sj;
  
  // (rt - 1) / st -> T
  // (rj - 1) / sj -> J
  ll k = 10000; 
  ll Tx = (rt - 1) * k, Ty = (int)(st * (k * 1.0));
  ll Jx = (rj - 1) * k, Jy = (int)(sj * (k * 1.0));

  // T > J
  if (Tx * Jy > Jx*Ty){
    cout << "JAKARTA";
  }
  else if (Tx * Jy < Jx * Ty){
    cout << "TAOYUAN";
  }
  else{
    cout << "SAME";
  }

  cout << endl;
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
