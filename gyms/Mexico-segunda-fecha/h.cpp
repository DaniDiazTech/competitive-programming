// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6 + 10;

vector<int> g[N];
int par[N], ans[N], group[N];
unordered_set<int> s;
unordered_map<int,int> mp;

void dfs(int u){
  if (u != 0){
    s.insert(group[u]); 
    mp[group[u]]++;
  }

  ans[u] = s.size();

  for (auto v: g[u]){
    if (v != par[u]){
      dfs(v);
    } 
  }

  if (u != 0){
    mp[group[u]]--;
    if (mp[group[u]] == 0){
      s.erase(group[u]);
    }
  }
}

void solve(){
  int n;
  cin >> n;

  for (int i = 1;i <= n; i++){
    cin >> par[i];
    g[i].push_back(par[i]);
    g[par[i]].push_back(i);
  } 

  for (int i = 1; i <= n; i++){
    cin >> group[i];
  }

  dfs(0);

  for (int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
