// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int xc, yc, k; cin >> xc >> yc >>k;

  int x[k], y[k];
  int  i = 0;

  int curx = xc, cury = yc;
  curx++;
  cury++;
  if (k & 1){
    x[i] = xc;
    y[i] = yc;
    i++;
  }
  while (i < k){
    x[i] = curx; 
    x[i + 1] = -curx;

    y[i] = cury;
    y[i + 1] = -cury;

    curx++;
    cury++;

    i += 2; 
  }

  int X = 0, Y = 0;
  for (int i =0 ;i < k; i++){
    X += x[i];
    Y += y[i];
    cout << x[i] << " " << y[i] << endl;
  }

  cout << X / k << " " << Y / k << endl;
  cout << endl;
  
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
