// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 1e6;

const int oo = 1e9;
int a[N];
int dp[N];

int n;

int go(int i){

  if (i > n){
    return oo;
  }

  if (dp[i] != oo) return dp[i];


  return dp[i] = min((go(i + 1) + 1), go(i + a[i] + 1));

}

void solve(){
  cin >> n;
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    dp[i] = oo;
  }
  dp[n] = 0;

  cout << go(0) << '\n';
  
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
