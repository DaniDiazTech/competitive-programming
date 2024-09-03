// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string s;cin >> s;
  if (s == "1111"){
    cout << yes << endl;
    return;
  }
  int z = 0;
  int block = 0;
  int i = 0;
  while (i < n){
    if (s[i] == '0'){
      block++;
      int now = 0;
      while (i < n && s[i] == '0'){
        now ++;
        i++;
      }
      z = now;
    }
    else{
      i++;
    }
  }
  // cout << z << " " << block << endl;
  cout << (z > 0 && (z + 2 == block + 2) ?  yes : no) << endl;
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
