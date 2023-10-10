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
#define vii vector<int> 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;


// int dp[MAX];
void solve(){
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> dp(n + 3), a(n + 3);
  vector<pii> cnt(m + 2);
  for (int i = 1; i <= n ; i++) cin >> a[i];

  for (int i = 1; i <= n; i++){
    dp[i] = max(cnt[min(m, i)].ff, cnt[min(m, i) - 1].ff + a[i] - d * (i - (cnt[min(m, i) -1].ss)));
    if (i != 1 && dp[i] >= cnt[min(m, i)].ff){
      cnt[min(m, i)] = {dp[i], i};
    }
  }

  cout << dp;
  for (auto x: cnt){
    cout << x << endl;
  }
  int mx = 0;
  for (auto x: dp) mx = max(x, mx);
  cout << mx << endl;
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
