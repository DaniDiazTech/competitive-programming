// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int ask(int a, int b){
  cout << "? " << a << " " << b << endl;
  int x; cin >> x;
  return x;
}

void solve(){

  int l = 1, r = 999; 

  while (l + 1 < r){
    int m1 = l + (r - l + 2) / 3;
    int m2 = r - (r - l + 2) / 3;

    int x = ask(m1, m2);
    if (x == m1 * (m2 + 1)){
      // inside
      l = m1;
      r = m2;
    }
    else if (x == m1 * m2){
      l = m2;
    }
    else{
      r = m1;
    }
  }

  cout << "! " << r << endl;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
