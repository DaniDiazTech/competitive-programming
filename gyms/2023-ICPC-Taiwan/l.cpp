// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n;
  cin >> n;

  ll X[n], Y[n];
  ll x = 0, y = 0;
  for (int i = 0;i < n; i++){
    cin >> X[i] >> Y[i];     
    x += X[i];
    y += Y[i];
  }

  x /= n; 
  y /= n;
  int k = 600;
  ll mn = 1e18;
  int ansx = 0, ansy = 0;
  for (int i = x - k; i <= x + k; i++){
    ll s = 0;
    for (int j = 0; j< n; j++){
      s += abs(X[j] - i);
    }
    if (s < mn){
      mn = s;
      ansx = i;
    }
  }
  mn = 1e18;
  for (int i = y - k; i <= y + k; i++){
    ll s = 0;
    for (int j = 0; j< n; j++){
      s += abs(Y[j] - i);
    }
    if (s < mn){
      mn = s;
      ansy = i;
    }
  }

  cout << ansx << " " << ansy << '\n';
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
