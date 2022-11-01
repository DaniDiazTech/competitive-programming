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
  // Capacity, current milk
  int a[3][3];
  for (int i = 0; i < 3; i++){
    cin >> a[i][0] >> a[i][1];
  }

  for (int i = 0; i < 100; i++){
    int now = i % 3;
    int then = (i + 1) % 3;
    // cout << "IND: " << now << " " << then << endl;
    if (a[now][1] + a[then][1] > a[then][0]){
      int r = a[then][1] + a[now][1] -  a[then][0];
      a[then][1] = a[then][0];
      a[now][1] = r; 
    }
    else{
      a[then][1] += a[now][1];    
      a[now][1] = 0;
    }
  }

  for (int i = 0; i < 3; i++){
    cout << a[i][1] << endl;
  }
}

int32_t main() {
  fastInp;
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
