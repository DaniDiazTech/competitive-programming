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
  string left = "", right = "";
  int n = sz(s);
  int i =0 ;
  for (; i < n / 2; i++){
    left += s[i];
  }
  left += (s[i + 1] == ')' ? '(' : ')');
  // close left
  string ansl = "", ansr = "";
  int cntl, cntr;
  cntl = cntr = 0;
  for (int j = 0; j < sz(left); j++){
    if (left[j] == ')'){
      cntr++;
      if (cntl != 0){
        forn(i,cntl) ansl.pb('(');
        forn(i,cntl) ansl.pb(')');
        cntl = 0;
      }
    }  
    else{
      cntl++;
      if (cntl != 0){
        forn(i,cntr) ansl.pb('(');
        forn(i,cntr) ansl.pb(')');
        cntr = 0;
      }
    }
  }
        // forn(i,cntl) ansl.pb('(');
        // forn(i,cntl) ansl.pb(')');
        // forn(i,cntr) ansl.pb('(');
        // forn(i,cntr) ansl.pb(')');
  for(; i < n; i++) right += s[i];
  cntl = cntr = 0;
  for (int j = 0; j < sz(right); j++){
    if (right[j] == ')'){
      cntr++;
      if (cntl != 0){
        forn(i,cntl) ansr.pb('(');
        forn(i,cntl) ansr.pb(')');
        cntl = 0;
      }
    }  
    else{
      cntl++;
      if (cntl != 0){
        forn(i,cntr) ansr.pb('(');
        forn(i,cntr) ansr.pb(')');
        cntr = 0;
      }
    }
  }
        // forn(i,cntl) ansr.pb('(');
        // forn(i,cntl) ansr.pb(')');
        // forn(i,cntr) ansr.pb('(');
        // forn(i,cntr) ansr.pb(')');
  string ans = ansl + ansr;
  cout << "S: " << s << endl;
  cout << "ANS";
  cout << ans << endl;
  for (int i =0 ; i < sz(ans); i++){
    string l= "";
    for(int j =0 ; j < n; j++){
      l += ans[j];
    }
    if (l == s){
      cout << "NO" << endl;
      return;
    }
  }
  cout << yes << endl;
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
