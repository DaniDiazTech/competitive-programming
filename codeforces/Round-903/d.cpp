// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N= 1e6 + 1000;
  // const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;

void solve(){
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    for (auto p: pr){
      if (p * p> x) break;
      while (x % p == 0){
        mp[p]++;
        x /= p;
      }
    }
    if (x > 1){
      mp[x]++;
    }
  }

  bool f= 1;
  for (auto x: mp){
    if (x.second % n != 0){
      // cout << x.first << " " << x.second << endl;
      f=0;
      break;
    }
  }
  cout << ( f ? yes : no) << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif


  for (int i=2; i <= N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= N; ++j) {
          lp[i * pr[j]] = pr[j];
          if (pr[j] == lp[i]) {
              break;
          }
      }
  }
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
