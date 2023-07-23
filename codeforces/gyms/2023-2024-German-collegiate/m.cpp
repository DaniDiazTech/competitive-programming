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


double n, m = 100;
bool check(double a, double b, double c){
  if (
    (a) == n || b == n || c == n ||
(a+b)== n || 
(a+b)== n || 
a+(b)== n || 
-(a+b)== n || 
-(a+b)== n || 
-a+(b)== n || 
-a+b== n || 
(a+b+c)== n || 
(a+b)+c== n || 
a+(b+c)== n || 
-(a+b+c)== n || 
-(a+b)+c== n || 
-a+(b+c)== n || 
-a+b+c== n || 
(a+b-c)== n || 
(a+b)-c== n || 
a+(b-c)== n || 
-(a+b-c)== n || 
-(a+b)-c== n || 
-a+(b-c)== n || 
-a+b-c== n || 
(a+b*c)== n || 
(a+b)*c== n || 
a+(b*c)== n || 
-(a+b*c)== n || 
-(a+b)*c== n || 
-a+(b*c)== n || 
-a+b*c== n || 
(a+b/c)== n || 
(a+b)/c== n || 
a+(b/c)== n || 
-(a+b/c)== n || 
-(a+b)/c== n || 
-a+(b/c)== n || 
-a+b/c== n || 
(a-b)== n || 
(a-b)== n || 
a-(b)== n || 
-(a-b)== n || 
-(a-b)== n || 
-a-(b)== n || 
-a-b== n || 
(a-b+c)== n || 
(a-b)+c== n || 
a-(b+c)== n || 
-(a-b+c)== n || 
-(a-b)+c== n || 
-a-(b+c)== n || 
-a-b+c== n || 
(a-b-c)== n || 
(a-b)-c== n || 
a-(b-c)== n || 
-(a-b-c)== n || 
-(a-b)-c== n || 
-a-(b-c)== n || 
-a-b-c== n || 
(a-b*c)== n || 
(a-b)*c== n || 
a-(b*c)== n || 
-(a-b*c)== n || 
-(a-b)*c== n || 
-a-(b*c)== n || 
-a-b*c== n || 
(a-b/c)== n || 
(a-b)/c== n || 
a-(b/c)== n || 
-(a-b/c)== n || 
-(a-b)/c== n || 
-a-(b/c)== n || 
-a-b/c== n || 
(a*b)== n || 
(a*b)== n || 
a*(b)== n || 
-(a*b)== n || 
-(a*b)== n || 
-a*(b)== n || 
-a*b== n || 
(a*b+c)== n || 
(a*b)+c== n || 
a*(b+c)== n || 
-(a*b+c)== n || 
-(a*b)+c== n || 
-a*(b+c)== n || 
-a*b+c== n || 
(a*b-c)== n || 
(a*b)-c== n || 
a*(b-c)== n || 
-(a*b-c)== n || 
-(a*b)-c== n || 
-a*(b-c)== n || 
-a*b-c== n || 
(a*b*c)== n || 
(a*b)*c== n || 
a*(b*c)== n || 
-(a*b*c)== n || 
-(a*b)*c== n || 
-a*(b*c)== n || 
-a*b*c== n || 
(a*b/c)== n || 
(a*b)/c== n || 
a*(b/c)== n || 
-(a*b/c)== n || 
-(a*b)/c== n || 
-a*(b/c)== n || 
-a*b/c== n || 
(a/b)== n || 
(a/b)== n || 
a/(b)== n || 
-(a/b)== n || 
-(a/b)== n || 
-a/(b)== n || 
-a/b== n || 
(a/b+c)== n || 
(a/b)+c== n || 
a/(b+c)== n || 
-(a/b+c)== n || 
-(a/b)+c== n || 
-a/(b+c)== n || 
-a/b+c== n || 
(a/b-c)== n || 
(a/b)-c== n || 
a/(b-c)== n || 
-(a/b-c)== n || 
-(a/b)-c== n || 
-a/(b-c)== n || 
-a/b-c== n || 
(a/b*c)== n || 
(a/b)*c== n || 
a/(b*c)== n || 
-(a/b*c)== n || 
-(a/b)*c== n || 
-a/(b*c)== n || 
-a/b*c== n || 
(a/b/c)== n || 
(a/b)/c== n || 
a/(b/c)== n || 
-(a/b/c)== n || 
-(a/b)/c== n || 
-a/(b/c)== n || 
-a/b/c== n 
  ){
    return true;
  }
  return false;
}

void solve(){
  for (int i = 1; i <= m - 3; i++){
    for (int j = i + 1; j <= m - 2; j++){
      for (int k = j + 1; k <= m; k++){
        if (!(check(i,j,k) || check(i, k, j) || check(k, i, j) || check(k, j, i) || check(j, i, k) || check(j, k, i))){
          cout  << "\""  << i << " " << j << " " << k << "\"," <<  endl;
          return;
        }
      }
    }
  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  // cin >> tc;

  for (n = 1; n <=100; n++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
