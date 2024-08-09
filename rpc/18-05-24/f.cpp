// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;


// Other pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int m = 21;
  int g[m][m];
  for (int i = 1; i < m; i++){
    for (int j = 1; j < m; j++){
      g[i][j] = __gcd(i, j);
    }
  }

  int n;
  cin >> n;
  set<int> unused = {1, 4, 8, 16, 11, 13, 17, 19};
  vector<int> f(21);

  for (int i = 0;i < n; i++){
    int x; cin >> x;
    f[x]++;
  }

  map<int,int> point;
  map<int, vector<int>> mp;
  for (int i = 2; i <= 20; i++){
    point[i] = i;
    mp[i] = {i};
  }

  mp[2] = {2, 4, 8, 16};
  mp[3] = {3, 9};
  mp[5] = {5, 15};
  // mp[7] = {7, 14};

  point[4] = point[8] = point[16] = 2;
  point[9] = 3;
  point[15] = 5;
  // point[14] = 7;

  set<int> spool;
  for (int i = 2; i<=20; i++){
    if (f[i] && unused.count(point[i]) == 0){
      spool.insert(point[i]);
    }
  }
  vector<int> pool;
  for (auto x: spool) pool.push_back(x);

  int mx = 0;

  do{
    vector<int> perm;
    for (auto x: pool){
      for (auto l: mp[x]){
        if (f[l])
          perm.push_back(l);
      }
    }
    int ans = 0;
    for (int i = 0;i < (int)perm.size(); i++){
      if (i > 0)
        ans += g[perm[i]][perm[i - 1]];
    }
    if (ans > mx){
      // for (auto x: perm) cout << x << ' ';
      // cout << endl;
    }
    mx = max(ans, mx);
  }
  while (next_permutation(pool.begin(), pool.end()));

  int x= 0;
  set<int> nocomb = {1, 11, 13, 17, 19};
  // 1 first
  int c = 0;
  for (auto l: nocomb){
    if (f[l]){
      c++;
    }
  }
  if (pool.size() > 0){
    x = c;
  }
  else{
    x = max(c - 1, 0);
  }

  for (int i = 1; i <= 20; i++){
    if (f[i])
      x += i * (f[i] - 1);
  }

  cout << mx + x << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
