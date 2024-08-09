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

  void print(){
    cout << "{" << x << ", " << y << "}";
  }

};

struct vect{
  point p; 
  vect(point x){
    p = x;
  }
  // Vector AB
  vect(point a, point b){
    p = b + (a * -1); 
  }

  // Proj of u over p
  vect proj(vect u){
    point projection = p * ((p.dot(u.p)) / (normSq()));
    return vect(projection);  
  }

  double normSq(){
    return p.dot(p);
  }
  double norm(){
    return sqrt(normSq());
  }
};


void solve(){
  int ax, ay, bx, by, cx, cy, r;
  cin >> ax >> ay >> bx >> by >> cx >> cy >> r;
  cout << setprecision(2) << fixed;

  point a(ax , ay);
  point b(bx , by);
  point c(cx , cy);
  
  vect ac(a, c);
  vect ab(a, b);


  auto proj = ab.proj(ac);

  vect bc(b, c);
  double closest = 1e9;
  double far = max(bc.norm(), ac.norm());
  if (proj.normSq() <= ab.normSq() && proj.p.dot(point(bx - ax, by - ay)) >= 0){
    closest = sqrt(ac.normSq() - proj.normSq());
  }
  else{
    closest = min(bc.norm(), ac.norm());
  }

  // cout << closest << " " << far << endl;

  double ans = max(0.0, -1.0 * r + closest);
  cout << ans << endl;
  cout << max(-1.0 * r + far, 0.0) << endl;
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
