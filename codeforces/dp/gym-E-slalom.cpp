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
const int ooo = -1e12;
const int mod = 1e9 + 7;


int a[1010][1010], dp[1010][1010];
int n;
int f(int i, int j){
  if (i >= n || j>=n) return 0;
  if (i == n -1) return a[i][j];
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = a[i][j] + max(f(i +1 , j), f(i +1, j + 1));
}
void solve(){
  cin >> n;
  forn(i,n){
    forn(j,n){
      if (j > i) a[i][j] = ooo / 2;
      else{
        cin >> a[i][j];
      }
      dp[i][j] = -1;
    }
  }
  cout << f(0,0) << endl;
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
