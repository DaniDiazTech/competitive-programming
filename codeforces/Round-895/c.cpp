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
  int l, r; cin >> l >> r;
  int prime = -1;
  if (l == 2){
    if (r > 3){
      cout << 2 << ' ' << 2 << endl;
    }
    else{
      cout << -1 << endl;
    }
    return;
  }
  for (auto p: primes){
    if (p > l) break;
    if (l % p == 0){
      prime = p;
      break; 
    }
  }
  if (prime == -1 || prime == l){
    // l is prime
    // try + 1, - 2
    // try l --  which is divisible by two
    if (l == r){
      cout << -1 << endl;
      return;
    }
    if (l> 2){
      cout << 2 << " " << l - 1 << endl;
    }
    else{
      if (l + 3 > r){
        cout << - 1 << endl;
      }
      else{
        cout << 2 << " " << l + 1 << endl;
      }
    }
  }
  else{
    cout << prime << " " << (l - prime) << endl;
  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n = 1e5;

  for (int i = 2; i <= n; i++){
    if (sieve[i]) continue;
    primes.pb(i);
    for (int j = i; j <= n; j += i){
      sieve[j] = 1;
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