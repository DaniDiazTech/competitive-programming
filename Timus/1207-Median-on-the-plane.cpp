// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
vector<pair<pair<double,double>, int>> a;

bool f(int i, int j){
  double m, b;
  int x1, x2, y1,y2;
  x1 = a[i].first.first, x2 = a[j].first.first;
  y1 = a[i].first.second, y2 = a[j].first.second;

  int up = 0, down = 0; 

  if (x1 == x2){
    for (int k = 0; k < (int)a.size(); k++){
      if (a[k].second == a[i].second || a[k].second == a[j].second){
        continue; 
      }
      int xk = a[k].first.first;
      if (xk > x1){
        up++;
      }
      else{
        down++;
      }
    } 
    return down == up;
  }
  else if (y1 == y2){
    for (int k = 0; k < (int)a.size(); k++){
      if (a[k].second == a[i].second || a[k].second == a[j].second){
        continue; 
      }
      int yk = a[k].first.second;
      if (yk > y1){
        up++;
      }
      else{
        down++;
      }
    } 
    return up == down;
  }

  m = (1.0 * (y2 - y1)) / (1.0 *(x2 - x1));
  b = y1 - m * x1;

  for (int k = 0; k < (int)a.size(); k++){
    if (k != i && k != j){
      double xk = 1.0 * a[k].first.first, yk = 1.0 * a[k].first.second;
      if (m * xk  + b > yk){
        up++;
      } 
      else if (m * xk + b < yk){
        down++;
      }
    }
  }

  return up == down;
}

void solve(){
  int n;
  cin >> n;
  for (int i = 1;i <= n; i++){
    pair<int,int> p;
    cin >> p.first >> p.second;
    a.push_back({p, i});
  }
  for (int i = 0;i < n; i++){
    for (int j = i + 1; j < n; j++){
      if (f(i, j)){
        cout << a[i].second  << " " << a[j].second << '\n';
        return;
      }
    }
  }
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
