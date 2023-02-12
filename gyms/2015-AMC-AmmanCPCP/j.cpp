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
void solve(){
  int n, m;
  cin >> n >> m;
  map<int, int> s;
  map<int, int> p;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    s[x]++;
  }
  for (int i = 0; i < m; i++){
    int x; cin >> x;
    p[x]++;
  }

  auto stu = s.begin();
  auto pac = p.begin();

  int ok  = 1;
  while (stu != s.end()){
    while ((*stu).second > (*pac).second && pac != p.end()){
      pac++;
    } 
    if (pac == p.end()){
      ok = 0;
      break;
    }
    // cout << (*stu).first << ": " << (*stu).second << " PAC: " << (*pac).first << "  cnt:  " << (*pac).second << endl;
    pac++;
    stu++;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
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
