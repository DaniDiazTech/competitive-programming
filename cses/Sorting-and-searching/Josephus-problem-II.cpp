// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;


void solve(){
  int n, k;
  cin >> n >> k;

  ordered_set s;
  if (k!= 0){
    for (int i = 1; i <= n; i++){
      s.insert(i);
    }
  }
  else{
    for (int i = 1; i <= n; i++){
      cout << i <<  " " ;
    }
    return;
  }
  int current = 0;

  while (s.size()){
    int next_index = (current +  k) % s.size();
    auto it = s.find_by_order(next_index);
    cout << *it << " ";
    s.erase(it);
    current = next_index;
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
