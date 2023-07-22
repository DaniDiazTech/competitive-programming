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


int dp[MAX][2];
vector<vii> v;
int s(int i, int j){
  if (dp[i][j] != -1) return dp[i][j];
  if (i >= sz(v)) return 0;
  if (j == 0){
    return dp[i][j] = max(s(i + 1, 0) , s(i + 1, 1));
  }
  // Searching for the next r
  int l = i, r = sz(v);
  while (l + 1 < r){
    int m = (l + r) / 2;
    if (v[m][0] > v[i][1]){
      r = m;
    }
    else{
      l = m;
    }
  }
  return dp[i][j] = max(s(r, 0), s(r, 1)) + v[i][2];
}
void solve(){
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  forn(i,n){
    int l, r, b; cin >> l  >> r >> b;
    v.pb(vii({l, r, b}));
  }
  sort(all(v));
  cout << max(s(0, 0), s(0, 1)) << endl;
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
