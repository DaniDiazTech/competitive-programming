// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  ll a[n], x[n];
  for (int i = 1;i < n; i++){
    cin >> x[i];
  }

  a[0] = x[1] + 1;
  a[0] *= 1000;
  cout << a[0] << " ";
  for (int i = 1; i < n; i++){
    a[i] = a[i - 1] + x[i];
    cout <<a[i] << " "; 
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
