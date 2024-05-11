// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  string a, b;cin>>a>>b;

  // cout << n << " " << m << endl;

  int j =0;
  int i = 0;

  for (;i < n && j < m; i++, j++){
    if (a[i] == '1'){
      while (j < m && b[j] != '1'){
        j++;
      }
      if (j >= m) break;
    }
    else{
      while (j < m && b[j] != '0'){
        j++;
      }
      if (j >= m) break;
    }
  }
  cout << i << endl;
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
