// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
int n , k;


bool valid(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < n;
}

///                 0   1   2   3   4   5   6   7
vector<int> dr = {-2, -2, -1, -1,  1,  1,  2,  2 };
vector<int> dc = {-1,  1, -2,  2, -2,  2,  -1,  1 };
// 625 max knigths
void solve(){
  cin >> n >> k;

  map<pair<int,int>, int> mp;
  map<int, pair<int,int>> to;
  vector<bool> vis(k);
  vector<int> score(k);
  set<pair<int,int>> s;

  for (int i = 0;i < k; i++){
    int x, y; cin >> x >> y;
    mp[{x, y}] = i;
    s.insert({x, y});
    to[i] = {x, y};
  }


  for (auto xx: mp){
    auto p = xx.first;
    for (int l = 0; l < 8; l++){
      int x = p.first + dr[l], y = p.second + dc[l];
      if (s.count({x, y})){
        score[xx.second]++;
      }
    }
  }

  int cnt= 0;
  // Take out maximum
  priority_queue<pair<int,int>> pq;
  for (int i = 0;i < k; i++){
    if (!vis[i]){
      pq.push({score[i], i});
    }
  }

  while (pq.size() && pq.top().first > 0){
    // re do
    cnt++;
    auto t = pq.top();
    vis[t.second] = 1;
    s.erase(to[t.second]);

    for (int i = 0; i < k; i++) score[i] = 0;
    for (auto xx: mp){
      if (vis[xx.second]) continue;
      auto p = xx.first;
      for (int l = 0; l < 8; l++){
        int x = p.first + dr[l], y = p.second + dc[l];
        if (s.count({x, y}) && !vis[mp[{x, y}]]) score[xx.second]++;
      }
    }
    // Recalculated
    while (pq.size()) pq.pop();
    
    for (int i = 0;i < k; i++){
      if (!vis[i]){
        pq.push({score[i], i});
      }
    }

  }
  cout << cnt << endl;
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
