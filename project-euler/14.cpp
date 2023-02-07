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

const int MAX = 1e7;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

// Stores numbers required to get to 1 
unordered_map<int, int> dp;
int solve(int n){
  if (n == 1){
    return 1;
  }
  if (dp.count(n) != 0){
    return dp[n];
  }
  if (n & 1){
    return dp[n] = solve((3 * n) + 1) + 1; 
  }
  else{
    return dp[n] = solve(n / 2) + 1;
  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  auto start = chrono::system_clock::now();
  int limit = 1e6;
  int mx = 0;
  // It makes sense to start searching from limit / 2
  // It's easy to see that c(2 * n) = c(n) +1.
  // Thus we can discard halve of the limit
  for (int i = limit / 2; i < limit; i++){
    mx = max(solve(i), mx);
  }
  auto end = chrono::system_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

  auto result = max_element(dp.begin(), dp.end(), [](const auto &a, auto const&b){return a.second < b.second ;});
  cout << "Element: " << (*result).first << " Chain: " << (*result).second << endl;

  return 0;
}
