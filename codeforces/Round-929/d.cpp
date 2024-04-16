// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){

  int n;
  cin >> n;
  
  int a[n];
  for (int i =0 ;i < n; i++) cin >> a[i];

  sort(a, a + n);
  if (a[0] < a[1]){
    cout << yes << '\n';
  }
  else{
    for (int i = 1;i < n; i++){
      if (a[i] % a[0] != 0){
        cout << yes << '\n';
        return;
      }
    }
    cout << no << '\n';
  }
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
