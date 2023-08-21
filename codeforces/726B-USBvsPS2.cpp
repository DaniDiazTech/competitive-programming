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
  int a, b, c;
  cin >> a >> b >> c;
  int m; cin >> m;
  vii u, p;
  forn(i,m){
    int x; cin >> x;
    string s; cin >> s;
    if (s[0] == 'U'){
      u.pb(x);
    }
    else{
      p.pb(x);
    }
  }
  sort(all(u));
  sort(all(p));
  int cnt =0;
  int sum =0 ;
  int i = 0;
  vii others;
  while (a > 0 && i < sz(u)){
    cnt++;
    a--;
    sum += u[i];
    i++;
  }
  for (; i < sz(u); i++) others.pb(u[i]);
  i = 0;
  while (b > 0 && i < sz(p)){
    cnt++;
    b--;
    sum += p[i];
    i++;
  }
  for (; i < sz(p); i++) others.pb(p[i]);
  sort(all(others));
  i =0;
  while (c > 0 && i < sz(others)){
    cnt++;
    c--;
    sum += others[i];
    i++;
  }
  cout << cnt << " " << sum << endl;
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
