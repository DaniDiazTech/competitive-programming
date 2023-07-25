// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
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
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


int a[3500][3500], c[3500][3500];
int q(int x1, int y1, int x2, int y2){
  int x= a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
  return x;
}
void solve(){
  int n, k;
  cin >> n >> k;
  forn(i,n){
    forn(j,n){
      int x = i + 1000;
      int y = j + 1000;
      cin >> c[x][y];
    }
  }
  forn(i,n + 1010){
    forn(j,n + 1010){
      int x = i + 1000;
      int y = j + 1000;
      a[x][y] = c[x][y] + a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1];
    }
  }
  if (k >= n){
    cout << a[n + 1001][n + 1001] << endl;
    return;
  }
  int mx = 0;
  for (int i = 1000; i< n+1000; i++){
    for (int j = 1000; j< n+1000; j++){
      int s = 0;
      for (int l = 0; l < k; l++){
        s += q(i - l, j - k + l, i + l, j - k + l);
      }
      for (int l = k; l >= 0; l--){
        s += q(i - l, j + (k - l), i + l , j + k - l);
      }
      mx = max(mx, s);
    }
    // cout << endl;

  }
  cout << mx << endl;
}

int32_t main() {
  fastInp;
  freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
