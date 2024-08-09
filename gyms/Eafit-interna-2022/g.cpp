// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N  = 51;
// Store ans
int dp[N][11][N][4 * N];

const int inf = 1e9;
int n;

// ones needed
vector<pair<int,int>> needed[10];
int go(int i, int sum, int five, int two){
  if (five < 0 || two < 0) return inf;
  if (i >= n) return 0;

  int &f = dp[i][sum][five][two];
  if (f != -1) return f;

  // Number of ones needed with this sum
  f = inf;
  // create five, two
  for (auto [fives, twos] : needed[sum]){
    int ones = sum - fives * 5 - twos * 2;
    int mx = -1;
    for (int k = 0; k <= 9; k++){
      mx = max(mx, go(i + 1, k, five - fives, two - twos));
    }
    f = min(f, ones + mx);
  }
  // cout << i << " " << sum << " " << five << " " << two  << " " << f << endl;

  return f;
}

void solve(int b){
  memset(dp, -1, sizeof dp);
  n = b;

  for (int k =0 ; k <= 9; k++){
    for (int fives = 0; fives <= 1; fives++){
      for (int twos = 0; twos <= 4; twos++){
        if (k >= fives * 5 + twos * 2){
          needed[k].push_back({fives, twos});
        }
      }
    }
  }

  int ans = inf;

  // Setteamos cantidad de 5 y de 2
  for (int i = 0;i <= n; i++){
    for (int j = 0; j <= 4 * n; j++){
      int mx  = - 1;
      for (int k =0 ; k <= 9; k++){
        mx = max(go(0, k, i, j), mx);
      }
      ans = min(ans, i + j + mx);
    }
  }

  cout << ans << "," << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int ans[] = {
      4,
      7,
      11,
      14,
      18,
      21,
      25,
      28,
      32,
      35,
      39,
      42,
      46,
      49,
      53,
      56,
      60,
      63,
      67,
      70,
      74,
      77,
      81,
      84,
      88,
      91,
      95,
      98,
      102,
      105,
      109,
      112,
      116,
      119,
      123,
      126,
      130,
      133,
      137,
      140,
      144,
      147,
      151,
      154,
      158,
      161,
      165,
      168,
      172,
      175 
  };
  int n; cin >> n;
  cout << ans[n - 1] << endl;
}
