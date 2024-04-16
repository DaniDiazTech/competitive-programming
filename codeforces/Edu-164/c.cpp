// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string a, b; cin >> a >> b;
  int n = a.size();
  bool first = 1;
  int i = 0;
  for (;i < n; i++){
    if (a[i] > b[i]){
      // increase b as much as possible
      first = 0;
      i++;
      break;
    }
    else if (a[i] < b[i]){
      // increase a as much as possible
      first = 1;
      i++;
      break;
    }
  }

  for (;i < n; i++){
    if (first){
      if (a[i] < b[i]) swap(a[i], b[i]);
    }
    else{
      if (a[i] > b[i]) swap(a[i], b[i]);
    }
  }
  
  cout << a << endl << b << endl;
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
