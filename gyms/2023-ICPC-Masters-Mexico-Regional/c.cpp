// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll n, r, g, b;

const int N = 22, M = 102;
ll dp[N][M][M][M];

ll perm[M], invperm[M];


ll binpow(ll a, ll b){
  if (b == 0) return 1;
  if (b == 1) return a;
  ll x = binpow(a , b / 2) % mod;
  return ( (  (x * x) % mod) * (b & 1 ? a : 1)) % mod;
}

ll go(int i, int r, int g, int b){
  if (r < 0 || g < 0 || b < 0) return 0;
  if (i == n + 1){
    return dp[i][r][g][b] = 1;
  } 
  if (dp[i][r][g][b] != -1){
    return dp[i][r][g][b];
  }

  dp[i][r][g][b] = 0;

  // All one color
  dp[i][r][g][b] += go(i + 1, r - i, g, b);
  dp[i][r][g][b] %= mod;

  dp[i][r][g][b] += go(i + 1, r, g - i, b);
  dp[i][r][g][b] %= mod;

  dp[i][r][g][b] += go(i + 1, r, g, b - i);
  dp[i][r][g][b] %= mod;

  // Two colors
  if (i % 2 == 0){
    // i / 2 -> c , 1 1 2 2, 1 1 2 2
    ll c = i / 2;
    // i! / ((c)! *  (c)!)
    ll x = (perm[i] * ((invperm[c] * invperm[c]) % mod)) % mod;

    dp[i][r][g][b] += x * go(i + 1, r - (i / 2), g - (i / 2), b);
    dp[i][r][g][b] %= mod;

    dp[i][r][g][b] += x * go(i + 1, r - (i / 2), g, b - (i / 2));
    dp[i][r][g][b] %= mod;

    dp[i][r][g][b] += x * go(i + 1, r, g - (i / 2), b - (i / 2));
    dp[i][r][g][b] %= mod;
  }

  if (i % 3 == 0){
    ll c = i / 3;
    // 10
    ll inv = ( (invperm[c] * invperm[c]) % mod ) * (invperm[c] ) % mod;
    ll x = (perm[i]  * inv) % mod;

    dp[i][r][g][b] += x * go(i + 1, r - (i / 3), g - (i / 3), b - (i / 3));
    dp[i][r][g][b] %= mod;
  }

  return dp[i][r][g][b];
}

void solve(){
  cin >> n >> r >> g >> b;
  memset(dp, -1, sizeof dp);
  perm[0] = invperm[0] = 1; 

  for (ll i =1;i < M; i++){
    perm[i] = (i * perm[i - 1]) % mod;
    invperm[i] = binpow(perm[i], mod - 2);
  }
  cout <<  go(1, r, g, b) << endl;
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
