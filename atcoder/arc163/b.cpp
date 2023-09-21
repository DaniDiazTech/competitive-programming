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
  cin >> n >> m;
  int l, r; cin >> l >> r;
  vii a(n - 2);

  for (int i = 0; i < n - 2; i++){
    cin >> a[i];
  }
  sort(all(a));
  // Search for first greater or equal than l
  int first = lower_bound(all(a), l) - a.begin();
  // Search for last less or equal to r
  int second = upper_bound(all(a), r) - a.begin();
  if (a[second] > r) second--;

  int ans = second - first + 1;
  // Lower bound first -> more effective
  vector<int> sol;
  int i = first - 1;
  // current cost
  int cur = 0;
  while (i >= 0){
    cur = abs(l + cur - a[i]);
    sol.pb(cur); 
    i--;
  }
  cur = 0; 
  i = second + 1;
  while (i < n){
    int x = a[i] - r;
    sol.pb(x);
    i++;
  }
  sort(all(sol));
  int sum = 0;
  i = 0;
  while (ans < m){
    sum += sol[i];
    ans++;
    i++;
  }
  cout << sol;
  cout << sum << endl;
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
