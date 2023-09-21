// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
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
  int n, c, d;
  cin >> n >> c >> d;
  vii a(n);
  int first_sum = 0;
  forn(i,n){
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < min(sz(a), d); i++){
    first_sum += a[i];
  }
  if (a[0] * d < c){
    cout << "Impossible" << endl;
    return;
  }
  if (first_sum >= c){
    cout << "Infinity" << endl;
    return;
  }

  vii p(n);

  forn(i,n){
    p[i] = a[i];
    if (i !=0 ){
      p[i] +=p[i - 1];
    }
  }
  int l = 0,  r = 2 * 10e9;
  while (l + 1 <r){
    int m = (l + r) / 2;
    // Simulation
    int sum = 0;
    int x = p[min(m, sz(a) - 1)];
    // ceil sum
    sum = ((d) / (m + 1)) * x;
    // Add extra
    if (d > m + 1 && d % (m + 1) != 0){
      int extra = d % (m + 1);
      sum += p[min(extra - 1, sz(a) - 1)];
    }

    // cout << l << " " << r << " " << m << endl;
    // cout << "SUM: " << sum << endl;

    if (sum >= c){
      l = m;
    }
    else{
      r = m;
    }
  }

  cout << l << endl;
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
