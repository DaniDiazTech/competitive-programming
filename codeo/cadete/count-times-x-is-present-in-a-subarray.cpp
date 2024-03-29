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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

// int arr[MAX];
void solve(){
  int n;
  cin >> n;
  unordered_map<int, vii> mp;
  forn(i,n){
    int x; cin >> x;
    mp[x].pb(i);
  }
  int q; cin >> q;
  forn(i,q){
    int l,r,x; cin >> l >> r >> x;
    if (!mp[x].size()){
      cout << 0 << endl;
      continue;
    }
    int ll = lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
    int rr = upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin();
    cout << rr - ll << endl;
  }
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
