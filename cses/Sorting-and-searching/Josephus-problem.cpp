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
void solve_1(){
  int n;
  cin >> n;

  vector<int> v;

  for (int i = 1;i <= n;i++) v.pb(i);

  while (v.size() > 1){
    vector<int> survivors;
    for (int i = 0 ; i < (int)v.size(); i++){
      // Remove second elements, and save survivors
      if (i % 2 == 1){
        cout << v[i] << " ";
      }
      else{
        survivors.pb(v[i]);
      }
    }
    // Even
    if ((int)v.size() % 2 == 0){
      v =  survivors;
    }
    else{
      int start = survivors.back();
      v.clear();
      v.pb(start);
      for (auto x: survivors){
        v.pb(x);
      }
      v.pop_back();
    }
    survivors.clear();
  }
  // Print last element
  cout << v[0];
}


void solve(){
  int n; cin >> n;
  vector<int> a;
  for (int i = 1; i <= n; i++) a.pb(i);

  int cnt  = 0, num = 0, i = 0;
  while (true){
    while (!a[i] && i != n  -  1)
      i++;
    if (a[i]) cnt++;

    if (cnt == 2){
      // Keep count of the numbers we've printed
      num++;
      cout << a[i] << " ";
      // Mark the number as visited
      a[i] = 0;
      cnt = 0;
    }
    // If limit is reached then start from zero
    if (i == n - 1){
      i = 0;
    }
    else i++;

    // Finish the while loop
    if (num == n) break;
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
