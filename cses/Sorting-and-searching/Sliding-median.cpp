// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 

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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

// int arr[MAX];
void solve(){
  int n, k;
  cin >> n >> k; 
  int a[n]; forn(i,n) cin >> a[i];
  indexed_multiset s;
  forn(i,k) s.insert(a[i]);
  fore(i, k, n){
    cout << (*s.find_by_order((k -1) / 2)) << " ";
    auto it = s.find_by_order(s.order_of_key(a[i - k]));
    s.erase(it);
    s.insert(a[i]);
  }
  cout << (*s.find_by_order((k-1) / 2)) << " ";
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
