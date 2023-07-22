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


// int dp[MAX];
void solve(){
  int n;
  cin >> n;
  vii a(n + 1), dp(1010);
  dp[n] = -1;
  forn(i,n){
    char ch; cin >> ch;
    a[i + 1] = (ch != '.' ? (ch == 'w' ? -1 : 1) : 0);
  }
  if (a[1] == -1){
    cout << -1 << endl;
    return;
  }
  dp[1] = a[1];
  dp[n] = -1;
  for (int i = 2; i <= n; i++){
    bool f = 0;
    int mx = 0;
    if (a[i] == -1) continue;
    for (int j = 1; j <=5; j+=2){
      if (i - j > 0 && a[i - j] != -1){
        f = 1;
        mx = max(dp[i - j], mx);
      }
    }
    if (f){
      dp[i] = mx + a[i];
    }
    else a[i] = -1;
  }
  cout << dp[n] << endl;

}

int32_t main() {
  fastInp;
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
