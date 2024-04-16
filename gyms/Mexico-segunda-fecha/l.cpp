// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 51, M = 505;

int sum = 0;
int n, a, b, c;

int p[N], dp[N][M][M];

int go(int i, int s1, int s2){
  if (i == n){
    int s3 = sum - s1 - s2;
    return dp[i][s1][s2] =  max((s1 + a - 1) / a, max((s2 + b - 1) / b, (s3 + c - 1) / c)); 
  }
  if (dp[i][s1][s2] != 0){
    return dp[i][s1][s2];
  }

  return dp[i][s1][s2] = min(go(i + 1, s1 + p[i], s2), min(go(i + 1, s1, s2 + p[i]), go(i + 1, s1, s2)));
}

void solve(){
  cin >> n >> a >> b >> c;
  for (int i =0 ;i < n; i++){
    cin >> p[i];
    sum += p[i];
  }
  cout << go(0, 0, 0) << endl;
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
