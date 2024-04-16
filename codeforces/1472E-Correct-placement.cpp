// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int inf = 1e9 + 1;
void solve(){
  int n;
  cin >> n;
  vector<pair<int,int>> a(n), pre(n);
  vector<int> index(n), ans(n, -1);
  pair<int,int> mn = {inf, -1};
  for (int i =0;i < n; i++){
    cin >> a[i].first >> a[i].second;
    index[i] = i;
  }
  // hi > hl
  sort(index.begin(), index.end(), [&](int i, int j){
    if (a[i].first == a[j].first) return a[i].second < a[j].second;  
    return a[i].first < a[j].first;
  });

  for (int i =0;i < n; i++){
    if (a[index[i]].second < mn.first){
      mn = {a[index[i]].second, index[i]};
    }
    pre[i] = mn;
  }

  for (int i = 0;i < n; i++){
    int l = -1, r = n ;
    while (l + 1 < r){
      int m = (l + r) / 2;
      if ( a[index[m]].first < a[i].first ) l =m;
      else r = m;
    }
    if (l == - 1) continue;
    if (pre[l].first < a[i].second){
      ans[i] = pre[l].second + 1;
    }
  }

  // hi > wi
  sort(index.begin(), index.end(), [&](int i, int j){
    if (a[i].second == a[j].second) return a[i].first < a[j].first;
    return a[i].second < a[j].second;  
  });
  // minimum first
  mn = {inf, -1};
  for (int i =0;i < n; i++){
    if (a[index[i]].first < mn.first){
      mn = {a[index[i]].first, index[i]};
    }
    pre[i] = mn;
  }
  
  for (int i = 0;i < n; i++){
    int l = -1, r = n ;
    while (l + 1 < r){
      int m = (l + r) / 2;

      if (a[index[m]].second < a[i].first) l = m;      
      else r = m;

    }
    if (l == - 1) continue;
    if (pre[l].first < a[i].second){
      ans[i] = pre[l].second + 1;
    }
  }

  for (auto x: ans) cout << x << " ";
  cout << '\n';

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
