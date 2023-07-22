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


int n = 8;
int dp[10][10], a[10][10];
int f(int i, int j){
  if (i >= n || j < 0){
    return oo;
  }
  if (i == n - 1 && j == 0) return a[i][j];
  return dp[i][j] =  a[i][j] + min(f(i, j - 1), min(f(i + 1, j), f(i + 1, j - 1)));
}
void solve(){
  forn(i,n){
    forn(j,n){
      cin >> a[i][j];
      dp[i][j] = -1;
    }
  }
  dp[n - 1][0] = a[n - 1][0];
  cout << f(0,7) << endl;
}

int32_t main() {
  fastInp;
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
