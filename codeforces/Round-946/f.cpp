// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int a, b, n, m;
  cin >> a >> b >> n >> m;
  vector<pair<int,int>> points(n);
  map<pair<int,int>, int> used;
  for (auto &c: points) cin >> c.first >> c.second;

  sort(points.begin(), points.end());
  deque<pair<int,int>> X, Y;
  for (auto p: points) X.push_back(p);
  sort(points.begin(), points.end(), [](const pair<int,int> &c, const pair<int,int> &d){
    return c.second < d.second;
  });

  for (auto p: points) Y.push_back(p);

  vector<int> score(2);
  int xl = 1 , xr = a, yl = 1, yr  = b;
  for (int turn  = 0; turn < m; turn++){
    char op; cin >> op;
    int k; cin >> k;
    if (op == 'U'){
      // cut first rows
      xl += k;
    }
    if (op == 'D'){
      xr -= k;
    }
    if (op == 'L'){
      yl += k;
    }
    if (op == 'R'){
      yr -= k;
    }
    // X
    while (X.size() && X.front().first < xl){
      auto p = X.front();
      X.pop_front();
      if (!used.count(p)){
        score[turn % 2]++;
        used[p]++;
      }
    }
    while (X.size() && X.back().first > xr){
      auto p = X.back();
      X.pop_back();
      if (!used.count(p)){
        score[turn % 2]++;
        used[p]++;
      }
    }

    while (Y.size() && Y.front().second < yl){
      auto p = Y.front();
      Y.pop_front();
      if (!used.count(p)){
        score[turn % 2]++;
        used[p]++;
      }
    }
    
    while (Y.size() && Y.back().second > yr){
      auto p = Y.back();
      Y.pop_back();
      if (!used.count(p)){
        score[turn % 2]++;
        used[p]++;
      }
    }
  }
  cout << score[0] << ' ' << score[1] << endl;
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
