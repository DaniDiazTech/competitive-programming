#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5;
vector<int> g[N];
bool vis[N];

vector<int> order; // Topological sort vector
void dfs(int u){
  vis[u] = 1; 
  for (auto v: g[u]){
    if (vis[v]) continue;
    dfs(v);
  }
  order.push_back(u);
}
/*
Toposort: Linear sorting of vertices such that every
vertex u comes before of any of its v successors.
*/
void toposort(){
  for (int i = 1;i <= N; i++){
    if (!vis[i]){
      dfs(i);
    }
  }
  reverse(order.begin(), order.end());
}