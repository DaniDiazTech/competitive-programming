// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const int N= 1e6 + 1000;
int sieve[N];

vector<int> primes;
void solve(){
  int n;
  cin >> n;
  unordered_map<int, int> mp;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    for (auto p: primes){
      if (p > x) break;
      while (x % p == 0){
        mp[p]++;
        x /= p;
      }
    }
  }
  bool f= 1;
  for (auto x: mp){
    if (x.second % n != 0){
      // cout << x.first << " " << x.second << endl;
      f=0;
      break;
    }
  }
  cout << ( f ? yes : no) << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  for (int i = 2;i < N; i++){
    if (sieve[i]) continue;
    primes.push_back(i);
    for (int j = i ; j < N; j+=i){
      sieve[j] = i;
    }
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}