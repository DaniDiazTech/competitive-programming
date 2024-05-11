// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

struct point{
  double x, y;
  point(int xx, int yy){
    x = xx * 1.0;
    y = yy * 1.0;
  }
  point(double xx, double yy){
    x = xx;
    y = yy;
  }
  /*
  Returns true if the line between the two points
  is not horizontal.
  */
  bool slope(point p, double &s){
    if (p.x == x){
      s = 0;
      return 0;
    }
    else{
      s = (y - p.y)  / (x - p.x);
      return 1;
    }
  }
  /*
  Returns line formed with two points.
  {slope, y-intercept}
  */
  bool line(point p, pair<double, double> &ans){
    double m;
    bool f = slope(p, m);
    if (!f){
      ans = {0, 0};
      return f;
    }
    
    ans.first = m;
    // Evaluate in second point
    ans.second = p.y -  m * p.x;
    return f;
  }
};

void solve(){
  int n;
  cin >> n;
  map<int, int> X;
  vector<point> a;

  for (int i  = 0;i < n; i++){
    int x, y; cin >> x >> y;
    a.push_back(point(x, y));
    X[x]++;
  }
  set<pair<double,double>> lines;

  for (int i =0 ;i < n; i++){
    for (int j = i + 1; j < n; j++){
      pair<double, double> l;
      bool f = a[i].line(a[j], l);
      if (f){
        lines.insert(l);
      }
    }
  }
  int ans = 0;
  for (auto p: X){
    ans = max(ans, p.second);
  } 
  double eps = 1e-7;
  for (auto line: lines){
    int cnt =0;
    for (auto p: a){
      if (fabs(((p.y) * 1.0) - (line.first * p.x + line.second) ) < eps){
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << '\n';

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
