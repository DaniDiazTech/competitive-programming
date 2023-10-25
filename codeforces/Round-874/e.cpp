// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 3 * 1e5;

int vis[N], par[N], color[N], in[N];

int two = 0;
vector<int> g[N];
vector<set<int>> cycles;

int comp =  0;
vector<vector<int>> components;
vector<int> curent;
void dfs(int u){
  color[comp]++;
  vis[u] = 1;
  curent.push_back(u);
  for (auto x: g[u]){

    if (vis[x] == 1){
      int cnt = 1;
      set<int> s;
      for (int l = u; l != x;l=par[l]){
        s.insert(l); 
      }
      s.insert(x);
      cycles.push_back(s);
    }
    else if (!vis[x]){
      par[x] = u;
      dfs(x);
    }
  }
  vis[u] = 2;
}

void solve(){
  int n;
  cin >> n;
  comp = 0;
  two = 0;
  cycles.clear();
  curent.clear();
  components.clear();
  for (int i =0 ;i < n + 10; i++){
    g[i].clear();
    vis[i] = 0;
    par[i] = 0;
    in[i] = 0;
  }

  for (int i =1 ;i <= n; i++){
    int x; cin >> x;
    in[x]++;
    in[i]++;
    g[i].push_back(x);
    g[x].push_back(i);
  }

  for (int i = 1; i <= n; i++){

    if (!vis[i]){
      dfs(i); 
      comp++;
      components.push_back(curent);
      curent.clear();
    }
  }
  int trees = 0;
  for (auto x: components){
    // cout << "COMPONENT: ";
    if (x.size() == 2){
      trees++;
      continue;
    }
    for (auto l: x){
      // cout << l << " ";
      if (in[l] == 1){
        trees++;
        break;
      }
    }
    // cout << endl;
  }
  // cout << "TREES: " << trees << endl;
  // cout << "TWO: " << two << '\n';
  // collapse all two into one
  cout << (comp + (trees >= 2 ? -trees + 1 : 0)) << " " << comp << '\n';

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
