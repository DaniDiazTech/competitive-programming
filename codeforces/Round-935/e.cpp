// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, x;
  cin >> n >> x;
  int p[n];
  int px = 0;
  for (int i = 0;i < n; i++){
    cin >> p[i];
    if (p[i] == x){
      px = i; 
    }
  }

  int l = 0, r = n;
  while (true){
    if (r - l == 1) break;
    int m = (l  + r ) / 2;
    if (p[m] <= x){
      l = m;
    }
    else r = m;
  }
  
  if (p[l] == x){
    cout << 0;
  }
  else{
    cout << 1 << '\n';
    cout << px + 1 << " " << l  + 1;
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
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
