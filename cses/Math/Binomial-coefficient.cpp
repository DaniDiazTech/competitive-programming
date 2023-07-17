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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

const int N = 10e6 + 1;

int fact[N];
int div[N];

int binpow(int b, int p){
  return (((binpow(b, p / 2) * binpow(b, p / 2)) % mod) * (b % 2 == 1 ? b : 1) % mod;  
}

void solve(){
  int n;
  cin >> n;
  fact[0] = fact[1] = 1;
  
  fore(i,2,N){
    fact[i] = (i * fact[i - 1]) % mod;
    div[i] = binpow(i, mod - 2);
  )}

  forn(i,n){
    int a, b; cin >> a >> b;
    cout << (fact[a] * div[(fact[a] * fact[a - b]) % mod]) % mod << endl;
  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
