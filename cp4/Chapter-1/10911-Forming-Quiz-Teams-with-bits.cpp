// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define LSB(S) (S & -(S))

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int n;
double dis[20][20], dp[1 << 17];
int X[20], Y[20];

double go(int mask){
  if (mask == 0 ) return 0; 
  double &ans = dp[mask];
  if (ans > -0.5) return ans;

  ans = 1e9;
 
  int first_power_turned_on = LSB(mask);
  int first_point = __builtin_ctz(first_power_turned_on);

  int m = mask;
  m -= first_power_turned_on;

  while (m){
    int second_power_turned_on = LSB(m);
    int second_point = __builtin_ctz(second_power_turned_on);

    m -= second_power_turned_on;
    ans = min(ans, dis[first_point][second_point] + go(mask ^ second_power_turned_on ^ first_power_turned_on));
  }

  return ans;
}

void solve(){
  memset(dp, -1.0, sizeof(dp[0])*((1 << (2 * n))));
  for (int i = 0; i < 2 * n; i++){
    string s; cin >> s;
    cin >> X[i] >> Y[i];
  }
  for (int i =0 ; i < 2 * n; i++){
    for (int j =0 ;j < 2 * n ; j++){
      dis[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]);
    }
  }

  cout << go((1 << (2 * n)) - 1);
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  cout << fixed << setprecision(2);
  while (cin >> n){
    if (n == 0) break;
    cout << "Case " << t++ << ": ";
    solve();
    cout << endl;
  }
}
