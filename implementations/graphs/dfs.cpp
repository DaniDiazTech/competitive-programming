#include <bits/stdc++.h>
using namespace std;

const int N = 5;
vector<int> g[N];
int vis[N];

// Current node: u
void dfs(int u){
  vis[u] = 1;
  for (auto v: g[u]){
    if (vis[v]){
      continue;
    }
    dfs(v);
  }
}


// Bicolored BFS