// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e5;
int n;

vector<ld> X(16), Y(16);
vector<ld> dp;


ld dis(int i, int j){
  return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
}

ld go(int mask){
  if (mask == (1 << (2 * n)) - 1){
    return 0;
  }
  if (dp[mask] != -1){
    return dp[mask];
  }
  ld ans  = 1e15;


  for (int i = 0 ;i < 2 * n; i++){
    if (mask & (1 << i)) continue;
    for (int j = i + 1; j < 2 * n; j++){
      if (mask & (1 << j)) continue;
      ans = min(ans, dis(i,j) + go(mask | (1 << i) | (1 << j)));
    }
  }

  return dp[mask] = ans;
}

void solve(){
  dp.assign((1 << (2 * n + 1)), -1);
  for (int i =0 ;i < 2 * n; i++){
    string s; cin >> s;
    int x,y; cin >> x >> y;
    X[i] = x;
    Y[i] = y;
  }
  cout << go(0);
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cout << fixed << setprecision(2);
  int t = 1;
  while (cin >> n){
    if (n == 0) break;

    cout <<  "Case " << t++ << ": ";
    solve();
    cout << endl;
  }
}
