// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6 + 2;
bool sieve[N];
vector<int> primes;

void solve(){
  for (int i = 2; i < N; i++){
    if (!sieve[i]){
      primes.push_back(i);
      for (int j = i; j < N; j += i){
        sieve[j] = 1;
      }
    }
  }

  ll n;
  cin >> n;
  int ans = 0;
  for (auto p: primes){
    if (1ll * p * p > n){
      break;
    }
    int l =0, j = 1;
    while (n % p == 0){
      n /= p;
      l++;
      if (j == l){
        ans++;
        l = 0;
        j++;
      }
    }
  }
  if (n > 1) ans++;

  cout << ans << endl;
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
