// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;

  vector<ll> X(n), Y(n); 
  for (int i =0;i < n; i++){
    cin >> X[i] >> Y[i];
  }
  ll xs,ys, xt,yt;
  cin >> xs >> ys >> xt >> yt;

  ll dis = (xs - xt) * (xs - xt) + (ys - yt) * (ys - yt);

  for (int i =0 ;i < n; i++){
    ll now = (X[i] - xt) * (X[i] -xt) + (Y[i] - yt) * (Y[i] - yt);      
    if (now <= dis){
      cout << no << endl;
      return;
    }
  }
  cout << yes << endl;
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
