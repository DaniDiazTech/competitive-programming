/*
Use with caution, may cause precision errors
with floats
*/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 2e7 + 100;
bool sieve[N];
vector<ll> dp(N, 1);

void solve(){
int c, d, x; cin >> c >> d >> x;
ll ans = 0;
for (ll g = 1; g * g <= x; ++g){
  if (x % g == 0){
    int y = (x / g) + d;
    if (y % c == 0){
      y /= c;
      ans += dp[y];
    }

    int t = x / g;
    if (t == g) continue;
    y = (x / t) + d;
    if (y % c == 0){
      y /= c;
      ans += dp[y];
    }
  }
}
cout << ans << '\n';
}

int main() {
cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

sieve[1] = sieve[0] = 1;
dp[1] = 1;
for (ll i = 2; i < N; i++){
  if (!sieve[i]){
    dp[i] = 2;
    for (ll j = 2 * i; j < N; j+= i){
      // Biggest i
      sieve[j] = i;
      dp[j] *= 2;
    }
  }
}

int tc = 1;
cin >> tc;

for (int t = 1; t <= tc; t++){
  solve();
}
}
