// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int M = 9 * 800, N = 801;

ll dp[N][2 * M + 100];

map<ll,ll> cnt, cntzero;

ll go(ll i, ll dif){
  if (i == 0){
    return dif == M;
  }

  auto &l = dp[i][dif];
  if (l != -1) return l;
  l = 0;
  if (i == 1){
    for (auto x: cntzero){
      l += go(i - 1, dif + x.first) * x.second; 
      l %= mod;
    }
  }
  else{
    for (auto x: cnt){
      l += go(i - 1, dif + x.first) * x.second; 
      l %= mod;
    }
  }
  return l;
}

void solve(){
  int n;
  cin >> n;
  cout << go(n, M) << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  memset(dp, -1, sizeof dp);


  for (int i = 0; i < 10; i++){
    for (int j =0 ; j < 10; j++){
      if (i != j)
        cnt[i - j]++;
    }
  }
  for (int i = 1; i < 10; i++){
    for (int j =1 ; j < 10; j++){
      if (i != j)
        cntzero[i - j]++;
    }
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
