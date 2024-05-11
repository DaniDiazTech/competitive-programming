// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

struct point{
  double x, y;
  point(){}
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


struct triangle{
  point p1, p2, p3;
  vector<point> v;
  triangle(){}
  triangle(point a, point b, point c){
    p1 = a;
    p2 = b;
    p3 = c; 
    v = {p1, p2, p3};
  }
  double area(){
    double cross = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
    return fabs(cross) / 2.0;
  }
  
  int semiarea(){
    return (int)((p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y));
  }

  bool disjoint(triangle b){
    for (auto X: v){
      for (auto Y: b.v){
        if (X.x == Y.x && X.y == Y.y){
          return false;
        }
      }
    }

    return true;
  }

  void print(){
    cout << "-----------\n";
    for (auto p: v){
      cout << p.x << " " << p.y << '\n';
    }
    cout << "-----------\n";
  }
};

vector<point> points;
vector<triangle> triangles;
vector<bool> vis;

int n;
double mn = 1e15;



void solve(){
  cout << setprecision(1) << fixed;
  cin >> n;
  points.resize(3 * n);
  vis.resize(3 * n);
  for (int i=0;i < 3 * n; i++){
    cin >> points[i].x >> points[i].y;
    vis[i] = 0 ;
  } 


  for (int i =0 ;i < 3 * n; i++){
    for (int j = i + 1; j < 3 * n; j++){
      for (int k = j + 1; k < 3 * n; k++){
        triangles.push_back(triangle(points[i], points[j], points[k]));    
      }
    }
  }

  sort(triangles.begin(), triangles.end(), [&](triangle &a, triangle &b){
    return a.semiarea() < b.semiarea();
  });

  for (int i = 0;i < (int)triangles.size(); i++){
    vector<triangle> pos;
    pos.push_back(triangles[i]);
    for (int j = i -1; j>=0; j--){
      bool f = 1;
      for (auto t: pos){
        f &= t.disjoint(triangles[j]);
      }

      if (f){
        pos.push_back(triangles[j]);
      }

      if ((int)pos.size() == n){
        mn = min(mn, fabs(triangles[i].area() - triangles[j].area()));
        break;
      }
    }
  } 

  cout << mn;
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
