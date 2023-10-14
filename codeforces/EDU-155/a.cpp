// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int fs, fe;
  cin >> fs >> fe;

  vector<pair<int,int>> v;

  bool f = 1;
  for (int i = 0; i< n - 1; i++){
    int a, b; cin >>a >> b;
    if (a >= fs){
      if (b >= fe) f = 0;
    }
  }
  cout << (f ? fs : -1) << endl;
  
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
