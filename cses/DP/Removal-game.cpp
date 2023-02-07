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

int dp[5001][5001];
int a[5001];
int solve(int i, int j){
  if (i == j)
    return dp[i][j] = a[i];
  if (dp[i][j] != MINF)
    return dp[i][j]; 
  return dp[i][j] = max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif


  int n; cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      dp[i][j] = MINF;
  }

  int total = 0;
  for (int i =0; i < n; i++){
    int x; cin >> x;
    a[i] = x;
    total += x;
  };

  cout <<  (total + solve(0, n - 1)) / 2 <<  endl;
  return 0;
}
