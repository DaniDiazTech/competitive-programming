// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N = 2000;
bool sieve[N];
vector<int> primes;

void solve(){
  for (int i = 2; i < N; ++i){
    if (!sieve[i]){
      primes.push_back(i);
      for (int j = i * i; j < N; j+= i){
        sieve[i] = 1;
      }
    }
  }
  int n;
  cin >> n;
  bool f = 0;
  for (auto p: primes){
    if (p * p > n) break;
    while (n % p == 0){
      if (f) cout << "*";
      cout << p;
      f = 1;
      n/=p;
    }
  }

  if (n > 1){
    if (f) cout << "*";
    cout << n;
  }
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
