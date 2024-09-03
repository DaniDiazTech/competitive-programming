// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

double eps = 1e-7;

struct point{
  int x, y;
  point(int xx, int yy){
    x = xx;
    y = yy;
  }
  // mid point in a segment  
  point loc(point b){
    return point(b.x - x, b.y - y);
  }

  bool same(point b){
    return (b.x - x) == 0  && (b.y - y) == 0;
  }

  void print(){
    cout << "(" << x << ", " << y << ")\n";
  }
};


void solve(){
  int n;
  cin >> n;
  vector<point> a;
  for (int i =0 ;i < n; i++){
    int x, y; cin >> x >>y;
    a.push_back(point(x, y));
  }
  if (n % 2==1){
    cout << no << endl;
    return;
  }

  for (int i =0;i < n / 2; i++){
    auto mid1 = a[i].loc(a[(i + 1) % n]);
    auto mid2 = a[(i + 1 + n / 2) % n].loc(a[(i + n / 2) % n]);

    if (!(mid1.same(mid2))){
      cout << no << endl;
      return;
    }
  }
  cout << yes << endl;
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
