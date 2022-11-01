// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

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

void solve_o_1(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans  = 0;

  // Which segment goes first
  if (c < a){
    // Swap
    swap(a, c);
    swap(b, d);
  }
  // First segment goes first
  if (b > c){
    // Overlap
    ans = max(b, d) - a;
  }
  else{
    // Difference between the two segments
    ans = (b - a) + (d - c);
  }
  cout << ans << endl;
}

void solve_o_n(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> v(110);
  for (int i = a; i < b; i++) v[i] = 1;
  for (int i = c; i < d; i++) v[i] = 1;
  int ans = 0;
  for (auto x: v) ans+=x;
  cout << ans << endl;
}

void solve(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int total = (b - a) + (d - c);  // the sum of the two intervals
	int intersection = max(min(b, d) - max(a, c), (int)0);  // subtract the intersection
	int ans = total - intersection;
   
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #else
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  #endif



  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
