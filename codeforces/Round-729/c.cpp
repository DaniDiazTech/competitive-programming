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


vii p;
int brute(int n){
  int s = 0;
  vii a,b;
  for (int i = 1; i <= n; i++){
    for (int j = 2; j <= n + 2; j++){
      if (i % j != 0){
        s = (s +  j) % mod;
        a.pb(j);
        cout << "(" << i << ", " << j << ") ";
        b.pb(s);
        break;
      }
    }
  }
  return s % mod;
}
void solve(){
  int n; cin >> n;
  int ans = (n) % mod;
  for (auto i: p){
    if (i > n) break;
    int x = n / i;
    ans = (ans + x) % mod;
  }
  cout << (ans % mod) << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int g = 1;
  for (int j = 1; j <= 129; j++){
    g = (g / __gcd(j, g) * j);
    if (g > 1e16) break;
    p.pb(g);
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
