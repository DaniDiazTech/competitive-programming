#include <bits/stdc++.h>
using namespace std;

#define ll long long
/*
Dijkstra implementation in O(nlogn + mlogn)
Using priority_queue
Distance can exceed 32 bit int
*/

const ll inf = 1e12;
const int N = 2 * 1e5;

// {distance, vertex}
vector<pair<ll,int>> g[N];

/*
Dijkstra stores two vectors of size n + 1 (works with 1-indexed vertex)
d: stores minimum distances
p: stores predecesessors
s: starting node
n: number of nodes
*/

void dijsktra(int s, int n, vector<ll> &d, vector<int> &p){
  d.assign(n + 1, inf);
  p.assign(n + 1, -1);

  // {distance, vertex}
  priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;

  pq.push({0, s});

  while (!pq.empty()){
    auto pr = pq.top();
    pq.pop();

    ll dis = pr.first, u = pr.second;

    // already marked u
    if (dis != d[u]) continue;

    for (auto edge: g[u]){
      int v = edge.second; 
      ll x = edge.first + d[u];

      if (x < d[v]){
        // found better path
        d[v] = x;
        p[v] = u;
        pq.push({d[v], v});
      }
    }
  }
}

