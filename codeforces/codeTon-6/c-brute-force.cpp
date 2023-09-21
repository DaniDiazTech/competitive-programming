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
  int n, k;
  cin >> n >> k;
  int a[n];
  int b[n][n];
  forn(i,n){
    cin >> a[i];
  }
  forn(i,n){
    forn(j,n){
      b[i][j] = min(a[i], a[j]);
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
  cout << "ANS: "  << endl;

  for (int c =1; c <= k; c++){
    int firstcol = oo, lastcol = 0, firstrow = oo, lastrow = 0;
    forn(i,n){
      forn(j,n){
        if (b[i][j] == c){
          firstcol = min(firstcol, i+1);
          lastcol = max(lastcol, i+1);
          firstrow = min(firstrow, j+1);
          lastrow = max(lastrow, j+1);
        }
      }
    }
    cout << max(lastcol - firstcol + 1 + lastrow - firstrow + 1, (int)0) << endl;
  }
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
