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


int number_divisors(int n){
  int ans = 1;
  int cnt = 0;
  while (n % 2 == 0){
    n /= 2;
    cnt++;
  }
  ans *= (cnt + 1);

  for (int i = 3; i * i <= n; i+=2){
    cnt = 0;
    while (n % i == 0){
      n /= i;
      cnt++;
    }
    ans *= (cnt + 1);
  }
  if (n > 1){
    ans *= 2;
  }
  return ans;
}


// int arr[MAX];
void solve(){
  int n; cin >> n;
  cout << number_divisors(n) << endl; 
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
