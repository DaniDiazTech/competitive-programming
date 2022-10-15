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

// int arr[MAX];

void search(int k, string mask, int n, vector<int> &v, int &ans){
  if (k == n + 1){
    // process
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; i++){
      if (mask[i] == '1'){
        s1 += v[i];
      }
      else{
        s2 += v[i];
      }
    } 
    int diff = abs(s1 - s2);
    ans = min(ans, diff);
    mask = "";
  }
  else{
    // includes 1
    mask.push_back('1');
    search(k + 1, mask, n, v, ans);
    // not 1
    mask.pop_back();
    mask.push_back('0');
    search(k + 1, mask, n, v, ans);
  }
}

void solve(){
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  // 2^n
  // Ok, ok, with bitmasks iteratively
  int ans = INF;
  for (int mask = 0; mask < (1 << n); mask++){
    int s1 = 0;
    int s2  = 0;
    for (int i = 0; i < n; i++){
      if (mask & (1 << i)){
        s1 += v[i];
      }
      else s2+=v[i];
    }
    ans =  min(ans, abs(s1 - s2));
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
