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


int n, c;
vii a(MAX);
int check(int w){
  int r = 0;
  forn(i,n){
    r += (a[i] + 2 * w) * (a[i] + 2*w);
    if (r > c) return 2;
  }
  if (r == c) return 1;
  else if (r > c) return 2;
  else return 3;
}
void solve(){
  cin >> n >> c;
  forn(i,n) cin >> a[i];
  int l = 0, r= 1e9 / 2;
  int ans = 0;
  while (l <= r){
    int m = (l + r) / 2;
    int x = check(m);
    if (x == 1){
      ans = m;
      break;
    }
    else if (x == 2){
      r = m - 1;
    }
    else{
      l = m + 1;
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

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
