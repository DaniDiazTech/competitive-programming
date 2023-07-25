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


// int dp[MAX];
void solve(){
  int n;
  cin >> n;
  int a[n];
  int l[n],r[n];
  forn(i,n) cin >> a[i];
  l[0] = a[0];
  r[n - 1] = a[n - 1];
  for (int i = 1; i<n ;i++){
    l[i] = __gcd(l[i - 1], a[i]);
  }
  for (int i = n - 2; i>=0; i--){
    r[i] = __gcd(a[i], r[i + 1]);
  }
  // for (int i = 0; i < n; i++) cout << l[i] << " ";
  // cout << endl;
  // for (int i = 0; i < n; i++) cout <<r[i] << " ";
  // cout << endl;
  int ans = max(r[1], l[n - 2]);
  for (int i=1; i < n - 1; i++){
    ans = max(ans, __gcd(l[i - 1], r[i + 1]));
  }
  cout << ans << endl;
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
