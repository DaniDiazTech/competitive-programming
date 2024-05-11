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

  bool slope(point p, double &s){
    if (p.x == x){
      s = 0;
      return 0;
    }
    else{
      s = (y - p.x)  / (x - p.x);
      return 1;
    }
  }
};

vector<point> pol;

double area(const vector<point>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

void solve(){
  int n;
  cin >> n;
  for (int i = 0;i < n; i++){
    int x, y; cin >> x >> y;
    pol.push_back(point(x, y));
  }
  double mn = 1e15;
  cout << setprecision(1) << fixed; 
  for (int i = 0;i < n; i++){
    for (int j = i + 1; j < n; j++){
      vector<point> a;
      vector<point> b; 

      for (int k =i ; k <= j; k++){
        a.push_back(pol[k]);
      }
      for (int k = j; k < n; k++){
        b.push_back(pol[k]);
      }
      for (int k = 0; k <= i; k++){
        b.push_back(pol[k]);
      }
      double a1 = area(a), a2 = area(b);
      mn = min(fabs(a1 - a2), mn);
    }
  }
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

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
