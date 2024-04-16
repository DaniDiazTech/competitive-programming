// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int is_hamiltonian(vector<vector<int>> &adj, int n){
  // Ending node, subset
  bool dp[n][1 << n];
  memset(dp, 0, sizeof dp);
  
  for (int i = 0; i < n; i++){
    dp[i][1 << i] = 1;
  }

  int mx = 1;

  for (int mask = 0; mask < (1 << n); mask++){
    for (int u = 0; u < n; u++){
      if (mask & (1 << u)){
        for (int v = 0; v < n; v++){
          // Can create a single path from v to u
          // Iff there is a single path ending at v not including u
          if (mask & (1 << v) && v != u && adj[u][v] && dp[v][mask ^ (1 << u)]){
            dp[u][mask] = 1;
            mx= max(mx, __builtin_popcount(mask));
          }
        }
      }
    } 
  }
  // modified function

  return mx;
}


void solve(){
  int n;
  cin >> n;
  unordered_map<string, int> genre, writer;
  int g = 0, w = 0;
  vector<vector<int>> adj(n, vector<int>(n));
  vector<pair<int, int>> v;

  for (int i =0 ; i < n; i++){
    string a, b; cin >> a >> b;
    if (!genre.count(a)){
      genre[a] = g++;
    }
    if (!writer.count(b)){
      writer[b] = w++;
    }
    v.push_back({genre[a], writer[b]});
  }

  for (int i = 0;i < (int)v.size(); i++){
    for (int j =0; j < (int)v.size(); j++){
      if (v[i].first == v[j].first || v[i].second == v[j].second){
        adj[i][j] = 1;
      }
    }
  }

  int cnt = is_hamiltonian(adj, n);
  cout << n - cnt << '\n';
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
