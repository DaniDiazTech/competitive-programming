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


bool sieve[MAX];
vii primes;
void solve(){
  int n;
  cin >> n;
  vii a(n + 2);
  vii ans;
  for (int p = 2; p<= n; p++){
    if (a[p]) continue;
    int x=p;
    while (x <= n){
      ans.pb(x);
      a[x] = 1;
      for (int j = 2; j <= p; j++){
        if (x * j > n){
          x = oo;
          break;
        }
        if (!a[x * j]){
          x *= j;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++){
    if (!a[i]) ans.pb(i);
  }
  // test
  set<int> s;

  // cout << endl << "N: " <<n << endl;
  // for (int i = 0; i < n - 1; i++){
  //   s.insert(__gcd(ans[i], ans[i + 1]));
  // }
  for (auto x: ans) cout << x << " ";
  cout << endl;
  // cout << ": " <<  sz(s) << endl;
  // cout << "GCDS: " << endl;
  // for (auto x: s) cout << x << " ";

}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
