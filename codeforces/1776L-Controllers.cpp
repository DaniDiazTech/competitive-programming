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
  int n;
  cin >> n;
  int pos, neg;
  pos = neg = 0;

  forn(i,n){
    char ch; cin >> ch;
    if (ch == '+'){
      pos++;
    }
    else neg++;
  }

  int q; cin >> q;
  while (q--){
    int a, b; cin >> a >> b;
    if (a == b){
      cout << (pos == neg ? "YES" : "NO") << endl;
      continue;
    }

    int nom = -1 * b * (pos - neg);
    int dem = (a - b);
    int k = nom / dem;
    bool inrange = k >= (-1 * neg) && (k <= pos) ;

    if (nom % dem == 0 && inrange){
      cout << "YES";
    }
    else
      cout << "NO";
    cout << endl;
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
