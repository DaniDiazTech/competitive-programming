// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6 + 10;

vector<int> g[N];
vector<int> freq(N), s(N);
// string to node
map<string, int> children[N];

int n = 0, T = 0, node = 1, mn = 1e8;

void dfs(int u, int p) {
  if (u != 0 && children[u].size() > 0){
    s[u] = s[p] + n - 2 * freq[u];
  }
  else s[u] = T;
  mn = min(mn, s[u]);

  for (auto v: g[u]){
    dfs(v, u);
  }
}

void solve() {
  string start;
  getline(cin, start);
  n = stoi(start);

  for (int i = 0;i < n; i++) {

    string line;
    getline(cin, line);
    line += '/';

    string cur = "";
    int par = 0;
    T--;
    for (auto x : line) {
      if (x == '/') {
        T++;
        if (cur.size()) {

          if (!children[par][cur]) {
            // add
            children[par][cur] = node;

            g[par].push_back(node);

            freq[node]++;
            par = node;
            node++;
          }
          else {
            freq[children[par][cur]]++;
            par = children[par][cur];
          }

        }

        cur = "";
      }
      else cur += x;
    }
  }

  s[0] = T;

  dfs(0, -1);

  cout << mn << '\n'; 

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
