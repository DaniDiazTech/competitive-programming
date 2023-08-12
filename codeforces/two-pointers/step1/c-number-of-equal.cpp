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
void solve1(){
  int n, m;
  cin >> n >> m;
  map<int, int> a,b;
  forn(i,n){
    int x; cin >> x;
    a[x]++;
  }
  forn(i,m){
    int x; cin >> x;
    b[x]++;
  }
  int ans = 0;
  for (auto x: a){
    ans += (x.ss * b[x.ff]);
  }
  cout << ans << endl;
}

void solve(){
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 1], ans = 0;
  forn(i,n) cin >> a[i];forn(i,m) cin >> b[i];
  int i =0, j =0;
  for (; i < n; i++){
    int mult = 1;
    while (i < n && a[i] == a[i + 1]) i++, mult++;
    while (j < m && b[j] < a[i]) j++;
    int l = j;
    if (a[i] != b[j]) continue;
    for (; l < m && b[l] == a[i]; l++){}
    l--;
    ans += (l - j + 1) * mult;
    j = l;
    // cout << i << " " << j << " " <<  ans << endl;
  }
  cout << ans << endl;
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
