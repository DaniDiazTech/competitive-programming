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
  int n, m, d;
  cin >> n >> m >> d;
  vii a(n);
  set<pair<int, int>> s;
  forn(i,n){
    int x; cin >> x;
    a[i]= x;
    s.insert({x, i});
  }
  map<int, int> ans;
  int day = 1, hour = 0;
  // Simulates each day
  while (!s.empty()){
    auto it = s.begin();
    pii p = (*it);
    ans[p.ss] = day;
    cout << "DAY: " << day << " current: " <<  p.ff  << endl;
    s.erase(it);
    hour = p.ff;
    while (!s.empty() && hour <= m){
      auto l = s.lower_bound({hour + d, 0});
      (l--);
      if (l == s.end()){
        day++;
        break;
      }
      pii pp = (*l);
      cout << p << " NEXT:  " << pp << endl;
      p = pp;
      if (hour > m){
        day++;
        break;
      }
      else{
        ans[pp.ss] = day;
        hour = pp.ff;
        s.erase(l);
      }
    }
  }
  cout <<day << endl;
  for (auto x: ans){
    cout << x.ss << " ";
  }
  cout << endl;
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
