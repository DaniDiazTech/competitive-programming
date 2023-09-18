// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;
typedef vector<int> vii;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int sieve[MAX];
vii primes;
void solve(){
  int a, m;
  cin >> a >> m;
  int ans = -1;
  int g = __gcd(a, m);
  // cout << g << endl;
  ans += m / g;
  int l = m;
  map<int, int> mp, gcdmp;

  for (auto p: primes){
    if (p > m) break;
    while (l % p == 0){
      mp[p]++;
      l /= p;
    }
  }
  if (l != 1){
    // l is prime
    mp[l]++;
  }
  l = g;
  for (auto p: primes){
    if (p > m) break;
    while (l % p == 0){
      gcdmp[p]++;
      l /= p;
    }
  }
  if (l != 1){
    gcdmp[l]++;
  }
  for (auto x: gcdmp){
    mp[x.ff] -= x.ss;
  }
  for (auto x: mp){
    cout << x << endl;
    if (x.ss > 0){
      ans -= m / (g * x.ff);
      // overcounting m
      ans++;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n = 1e5;
  for (int i = 2; i < n; i++){
    if (sieve[i]) continue;
    primes.pb(i);
    for (int j = i; j < n; j+=i){
      sieve[j] = i;
    }
  }
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
