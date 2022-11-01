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

// int arr[MAX];
int a[2010][2010];
void solve_n2(){
  // Brute force approach :(
  int v[3][4];
  forn(i, 3){
    forn(j, 4){
      cin >> v[i][j];
      v[i][j] += 1000;
    }
  }

  for (int rectangle = 0; rectangle < 3; rectangle++){
    int fill = 1;
    // Fill with 0s instead of ones
    if (rectangle == 2) fill = 0;
    // Y are rows
    for (int i = v[rectangle][1]; i < v[rectangle][3]; i++){
      // X are columns
      for (int j = v[rectangle][0]; j < v[rectangle][2]; j++){
        a[i][j] = fill;
      }
    }
  }
  int ans = 0;
  int n = 2001;
  forn(i, n){
    forn(j, n){
      ans += a[i][j];
    }
  }
  cout << ans << endl;
}

struct Rectangle{
  int x1, y1, x2, y2; 

  void get(){
    cin >> x1 >> y1 >> x2 >> y2;
  }

  int area(){
    return ((x2 - x1) * (y2 - y1));
  }

  int intersection(Rectangle r){
    int width = min(x2, r.x2) - max(x1, r.x1);
    int length = min(y2, r.y2) - max(y1, r.y1);
    if (width < 0 || length < 0){
      return 0;
    }
    return width * length;
  }
};

void solve_o1(){
  Rectangle R1;
  Rectangle R2;
  Rectangle R3;
  R1.get();
  R2.get();
  R3.get();

  int total = R1.area() + R2.area();
  int inter = R1.intersection(R3) + R2.intersection(R3);
  cout << total - inter << endl;
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

  solve_o1();
  return 0;
}
