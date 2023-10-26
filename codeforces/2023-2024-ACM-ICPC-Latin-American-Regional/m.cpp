// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

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

void dijsktra(int s, int n, vector<ll> &d, int no){
  d.assign(n + 1, inf);
  d[s] = 0;

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

      if (x < d[v] && v != no){
        // found better path
        d[v] = x;
        pq.push({d[v], v});
      }
    }
  }
}



void solve(){
  int n, m;
  cin >> n >> m;
  int s, goal; cin >> s >> goal;

  for (int i = 0;i < m; i++){
    int u, v;
    ll d;
    cin >> u >> v >> d;
    g[u].push_back({d, v});
    g[v].push_back({d, u});
  }

  vector<ll> disA, disB;
  dijsktra(goal, n, disA, -1);
  dijsktra(s, n, disB, goal);

  set<int> candidates;
  ll initial = disA[s];   
  for (int i = 1; i <= n; i++){
    if (disA[i] == initial && i != s){
      candidates.insert(i);
    }
  }
  vector<int> ans;
  for (auto x: candidates){
    if (disB[x] > disA[x]+ initial){
      ans.push_back(x);
    }
  }  

  if (ans.size()){
    for (auto x: ans){
      cout << x  << " ";
    }
  }
  else cout << "*";
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
