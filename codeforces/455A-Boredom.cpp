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

const int MAX = 1e5 + 10;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int dp[MAX];
int cnt[MAX];
vector<int> a;
int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n;
  cin >> n;
  forn(i,n){
    int x;
    cin >> x;
    cnt[x]++;
  }
  int N = 100;
  dp[0]= 0;
  for (int i = 1; i < N; i++){
    dp[i] = i * cnt[i];
    if (i -2 >= 0){
      dp[i] += dp[i - 2];
    }
    if (dp[i - 1] > dp[i]){
      dp[i] = dp[i - 1];
    }
    cout << dp[i] << endl;
  }

  cout << dp[N - 1];

  return 0;
}
