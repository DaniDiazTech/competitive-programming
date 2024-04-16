// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;

  map<int,int> mp;
  int a[n];
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  int cnt = 0;
  for (auto x: mp){
    // cout << x.first << " " << (x.first ^ ((1 << 31) - 1)) <<  " " << x.second << endl;;
    for (int i = 0;i < x.second; i++){
      if (mp[ (x.first ^ ((1 << 31) - 1)) ]){
        mp[ (x.first ^ ((1 << 31) - 1)) ]--;
      }
      cnt++;
    }
    mp[x.first] = 0;
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
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
