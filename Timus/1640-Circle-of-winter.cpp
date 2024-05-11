// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";



typedef double T;
struct point{
  T x, y;

  point(){
    x = y = 0;
  }

  point(T xx, T yy){
    x = xx;
    y = yy;
  }

  point operator + (point p){
    return {x + p.x, y + p.y};
  }

  point operator * (T s){
    return {s * x, s * y};
  }

  bool operator == (point p){
    return x == p.x && y== p.y;
  }

  bool operator != (point p){
    return !(*this == p);
  }

  T dot(point p){
    return p.x * x + p.y *y;
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
      s = ( 1.0 * (y - p.y))  / ( 1.0 * (x - p.x));
      return 1;
    }
  }

  double distance(point p){
    return sqrt( (x - p.x) * (x - p.x)  + (y - p.y) * (y - p.y)) ;
  }
};



void solve(){
  int n;
  cin >> n;
  point u(2000, 2000);
  vector<point> s;

  for (int i =0 ;i < n; i++){
    point v;
    cin >> v.x >> v.y;
    s.push_back(v);
  }
  cout << setprecision(20);
  double mx = 0;
  for (auto p: s){
    mx = max(mx, u.distance(p));
  }

  cout << u.x << " " << u.y << " " << mx << '\n';
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
