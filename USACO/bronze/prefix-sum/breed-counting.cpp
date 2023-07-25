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


  int p[MAX + 1][4];
void solve(){
  int n, q;
  cin >> n >> q;
  forn(i,n){
    int x; cin >> x;
    p[i + 1][x]++;
  }
  for (int i = 1;  i<= n; i++){
    p[i][1] += p[i - 1][1]; 
    p[i][2] += p[i - 1][2]; 
    p[i][3] += p[i - 1][3]; 
  }
  while (q--){
    int l, r; cin >> l >> r;
    cout << p[r][1] - p[l - 1][1] << " ";
    cout << p[r][2] - p[l - 1][2] << " ";
    cout << p[r][3] - p[l - 1][3] << endl;
  }

}

int32_t main() {
  fastInp;
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
