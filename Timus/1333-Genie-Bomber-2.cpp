// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

struct circle{
  double x, y, r;
  circle(double xx, double yy, double rr){
    x = xx;
    y = yy;
    r = rr;
  }

  bool in(double i, double j){
    // distance {i, j} - > {x, y}
    return r * r >= (x - i) * (x - i) + (y - j) * (y - j);
  }
};


void solve(){
  int n;
  cin >> n;

  vector<circle> a;
  for (int i =0 ;i < n; i++){
    double x, y, r; cin >> x >> y >> r;
    a.push_back(circle(x, y, r));
  }

  int M = 1000;
  int cnt = 0;  
  for (int i = 0;i <= M; i++){
    for (int j = 0; j <= M; j++){
      for (auto c: a){
        if (c.in((1.0 * i) / (1.0 * M), (1.0 * j) /  (1.0 * M))){
          cnt++;
          break;
        } 
      }
    }
  }
  cout << setprecision(10);
  cout << ((100.0 * cnt) / (1.0 * (M * M))) << '\n';
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
