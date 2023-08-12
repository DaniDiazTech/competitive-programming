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
  int n, m;
  cin >> n >>  m;
  vector<int> a(n), b(m);
  set<int> s;
  forn(i,n){
    int x;cin >> x;
    a[i] = x;
    s.insert(x);
  }
  int sum = 0, sumb = 0;
  forn(i,m){
    int x; cin >> x;
    b[i]=x;
    sumb += x;
    s.insert(x);
  }
  sort(all(a));
  sort(all(b));
  reverse(all(b));
  int ans = oo;
  int i = 0, j = m - 1, prev = 0;
  for (auto x: s){
    // simulate;
    while (i < n && x > a[i]){
      sum += a[i];
      i++;
    }
    while (j >= 0 && x >= b[j]){
      sumb -= b[j];
      j--;
    }
    ans = min((x * i - sum) + (sumb - x * (j  + 1)), ans);
  }
  cout << max((int)0, ans) << endl;
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
