// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, r , c;
  cin >> n >> r >> c;
  vector<bool> b(n);
  int i = 0;
  int j = n - 1, sz = n;


  vector<int> v;
  while (sz > 2){
    int rrun = r, crun = c;
    while (rrun > 1){
      if (b[i]){
        i++;
        i %= n;
        continue;
      }
      i++;
      rrun--;
      i %= n;
    }

    while (crun > 1){
      if (b[j]){
        j--;
        j += n;
        j %= n;
        continue;
      }
      j--;
      crun--;
      j += n;
      j %= n;
    }

    if (i == j){
      b[i] = 1;
      v.push_back(i + 1);
      sz--;
    }
    else{
      b[i] = b[j] = 1;
      sz -= 2;
    }
  }
  for (int i = 0;i < n; i++){
    if (!b[i]){
      v.push_back(i + 1);
    }
  }
  sort(v.begin(), v.end());
  for (auto x: v){
    cout << x << " ";
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
