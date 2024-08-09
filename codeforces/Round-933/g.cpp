// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;

  vector<set<int>> s(n + 1);
  map<int,int> colors;
  int ind = n + 1;

  for (int i =0 ;i < m; i++){
    int u, v, c; cin >> u >> v >> c;
    
    if (colors.find(c) == colors.end()){
      colors[c] = ind;
      ind++; 
    }

    s[u].insert(c);
    s[v].insert(c);
  }

  int b, e;
  cin >> b >> e;

  vector<int> g[ind + 1];

  for (int i = 1; i <= n; i++){
    for (auto x: s[i]){
      g[colors[x]].push_back(i);
      g[i].push_back(colors[x]);
    }
  }

  queue<int> q;
  q.push(b);
  vector<int> dis(ind + 1, -1);
  dis[b] = 0;

  while (q.size()){
    int u = q.front();
    q.pop();

    for (auto v: g[u]){
      if (dis[v] !=-1) continue;
      dis[v] = dis[u] + 1;
      q.push(v);
    }
  }


  cout << dis[e] / 2 << endl;
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
