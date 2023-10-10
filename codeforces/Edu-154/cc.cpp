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
  string s; cin >> s;
  vector<char> v;
  vector<int> req;
  bool f = 1;
  char prev = 'x';
  for (auto x: s){
    // cout << v;
    // cout << req;
    // cout << "----------" << endl;
    if (x == '0'){
      if (prev == '1') f =0;
    }
    if (x == '1'){
      if (prev == '0') f = 0;
    }

    if (x == '+'){
      v.pb('+');
    }
    if (x== '-'){
      v.pop_back();
      while (!req.empty() && req.back() > v.size()){
        req.pop_back();
      }
    }
    if (x == '0'){
      // the problem is:
      // array is sorted by definition
      if (sz(v)< 2){
        f = 0;
      }
      if (prev != '0'){
        req.pb(sz(v)); 
      }
    }
    if (x == '1'){
      // array must be unsorted
      // cout << req;

      if (req.size() && req[0] < v.size()){
        f = 0;
      }
    }
    prev = x;
  }

  cout << (f ? yes : no ) << endl;
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
