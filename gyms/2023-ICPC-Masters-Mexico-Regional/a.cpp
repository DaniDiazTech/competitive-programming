// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int l = 0, r = n - 1, cnt = 0;
  vector<int> a(n); for (auto &c: a) cin >> c;

  while (l <= r){

    if (a[l] == a[r]){
      l++;
      r--;
    }
    else if (a[l] < a[r]){
      a[l + 1] += a[l];
      l++;
      cnt++;
    }
    else{
      a[r - 1] += a[r];
      r--;
      cnt++;
    }
  }

  cout << cnt << '\n';
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
