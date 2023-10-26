#include <bits/stdc++.h>
using namespace std;

/*
Dijkstra implementation in O(nlogn + mlogn)
Using priority_queue
*/

const int inf = 1e9;
const int N = 2 * 1e5;

// {distance, vertex}
vector<pair<int,int>> g[N];

/*
Dijkstra stores two vectors of size n + 1 (works with 1-indexed vertex)
d: stores minimum distances
p: stores predecesessors
s: starting node
n: number of nodes
*/

void dijsktra(int s, int n, vector<int> &d, vector<int> &p){
  d.assign(n + 1, inf);
  p.assign(n + 1, -1);

  // {distance, vertex}
  priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

  pq.push({0, s});

  while (!pq.empty()){
    auto pr = pq.top();
    pq.pop();

    int dis = pr.first, u = pr.second;

    // already marked u
    if (dis != d[u]) continue;

    for (auto edge: g[u]){
      int v = edge.second; 
      int x = edge.first + d[u];

      if (x < d[v]){
        // found better path
        d[v] = x;
        p[v] = u;
        pq.push({d[v], v});
      }
    }
  }
}

