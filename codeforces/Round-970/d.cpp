// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n];
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    a[i]--;
  }

  string s;
  cin >>  s;

  int id = 0;
  int val = 0;

  vector<int> ids(n);
  vector<bool> vis(n);
  map<int,int> mp;

  function<void(int)> dfs = [&](int u){
    vis[u] = 1;
    ids[u] = id;
    if (s[u] == '0') val++;
    if (vis[a[u]]){
      // cycle
      return;
    }
    dfs(a[u]);
  };

  for (int i = 0;i < n; i++){
    val = 0;
    if (!vis[i]){
      dfs(i);
      mp[id] = val;
      id++;
    }
  }

  for (int i =0 ;i < n; i++){
    cout << mp[ids[i]] <<" ";
  } 
  cout << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
