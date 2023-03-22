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
  int neg = 0, pos = 0, value = 0;
  int a[n];
  forn(i,m){
    int x, d; cin >> x >> d;
    if (d <= 0){
      neg += d;
    }
    else{
      pos += d;
    }
    value += x;
  }
  forn(i,n) a[i] = value;
  
  int mid = n / 2;

  forn(i, n){
    a[i] += pos * (abs(n - 1 - i));
  }
  forn(i, n){
    a[i] += neg * (abs(i - mid));
  }
  double sum = 0;
  forn(i,n){
    sum += (double)a[i];
  }
  cout << setprecision(9) << (double)(sum / n) << endl;
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
