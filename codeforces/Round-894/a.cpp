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
#define vii vector<int> 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;


// int dp[MAX];
void solve(){
  int n, m;
  cin >> n >> m;
  vector<int> v, i, k, a;
  forn(j,n){
    string s;cin >> s;
    for (int l = 0; l < sz(s); l++){
      if (s[l] == 'v') v.pb(l);
      if (s[l] == 'i') i.pb(l);
      if (s[l] == 'k') k.pb(l);
      if (s[l] == 'a') a.pb(l);
    }
  }
  // cout << v << i << k << a;
  bool f= 0;
  for (int first = 0; first < sz(v); first++){
    forn(second, (sz(i))){
      forn(third, sz(k)){
        forn(fourth, sz(a)){
          f |= (v[first] < i[second] && i[second] < k[third] && k[third] < a[fourth]);
        }
      } 
    }
  }
  cout << (f ? "YES" : "NO") << endl;
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
