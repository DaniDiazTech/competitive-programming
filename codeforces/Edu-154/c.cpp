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
  string s;
  cin >> s;
  int requires = 0, cnt = 0, minus = 0, plus = 0;
  bool f = 1;
  // stores maximum values in which the values have to be descendant
  vii v;
  int i = 0;
  for (auto x: s){
    if (x == '+'){
      cnt++;
      plus++;
      i++;
    }
    if (x== '-'){
      cnt--;
      minus++;
      // wrong
      if (plus < minus && requires > 0) requires--;
      i--;
      while (!v.empty() && v.back() >= i) v.pop_back();
    }
    if (x == '0'){
      // the problem is:
      // array is sorted by definition
      if (cnt < 2){
        f = 0;
      }
      requires++;
      v.pb(i);
      minus = 0; plus = 0;
    }
    if (x == '1'){
      // array must be unsorted
      if (v.back() < cnt){
        f =0;
      }
      minus = 0; plus = 0;
    }
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