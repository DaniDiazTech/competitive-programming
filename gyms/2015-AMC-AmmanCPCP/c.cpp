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

const int MAX = 110;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;


int a[MAX];
void litup(int i, int n){
  a[i] = 2;
  if (i > 0 && a[i - 1] != 2){
    a[i - 1] = 1;
  }
  if (i < n - 1 && a[i + 1] != 2){
    a[i + 1] = 1;
  }
}
// int arr[MAX];
void solve(){
  for (int i =0; i < MAX; i++) a[i] = 0;
  int n;
  cin >> n;
  for (int  i  =0 ; i < n; i++){
    char ch; cin >> ch;
    if (ch == '*'){
      litup(i, n);
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == 0){
      litup(i  + 1, n);
      cnt++;
    }
  }
  cout << cnt;
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
    if (t > 1)  cout << endl;
    solve();
  }
  return 0;
}
