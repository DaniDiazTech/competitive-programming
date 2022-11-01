// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

struct Rectangle{
  int x1, y1, x2, y2;
  void get(){
    cin >> x1 >> y1 >> x2 >> y2;
  }
  int area(){
    return (x2 - x1) * (y2 - y1);
  }
};

int intersection(Rectangle r1, Rectangle r2){
  int width  = min(r1.x2, r2.x2) - max(r1.x1, r2.x1);
  int length = min(r1.y2, r2.y2) -  max(r1.y1, r2.y1);
  // Check if the intersection exists
  if (width < 0 || length < 0){
    return 0;
  }
  // But also if r1, covers r2 in the y axis
  // Or it can also cover in  the x axis

  // Covers the entire y axis, but not a part of the x axis
  if((r1.y2 >= r2.y2 && r1.y1 <= r2.y1) && (r1.x2 >= r2.x2 || r1.x1 <= r2.x1)){
    return width *  length;
  }
  if((r1.y2 >= r2.y2 || r1.y1 <= r2.y1) && (r1.x1 <= r2.x1 && r1.x2 >= r2.x2)){
    return width *  length;
  }
  return 0;
}
void solve(){
  Rectangle law, cow;  
  law.get();
  cow.get();
  int total = law.area();
  int inter = intersection(cow, law);
  cout << total - inter << endl;;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #else
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
