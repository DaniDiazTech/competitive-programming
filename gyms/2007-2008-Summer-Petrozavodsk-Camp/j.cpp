// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
  x += cnt * b;
  y -= cnt * a;
}

bool find_all_solutions(int a, int b, int c, int minx, int miny, int &xans) {
  int x, y, g;
  if (!find_any_solution(a, b, c, x, y, g))
    return 0;
  a /= g;
  b /= g;
  c /= g;

  int sign_a = a > 0 ? +1 : -1;
  int sign_b = b > 0 ? +1 : -1;

  shift_solution(x, y, a, b, (minx - x) / b);
  if (x < minx)
    shift_solution(x, y, a, b, sign_b);
  int lx1 = x;


  shift_solution(x, y, a, b, -(miny - y) / a);
  if (y < miny)
    shift_solution(x, y, a, b, -sign_a);
  int lx2 = x;
  // Check min first
  xans = max(lx1, lx2);
  // Check condition for y
  if (((c - a * (xans)) / b) < miny || xans < minx){
    return 0;
  }

  return 1;
}



void solve(){
  int n, m, a, k;
  cin >> n >> m >> a >> k;
  if (n == 0 && m == 0 && a == 0 && k == 0) return;
  int x;
  bool f = find_all_solutions(a, -m, n - k, 1, 0, x); 
  if (!f){
    cout << "Impossible\n";
  }
  else{
    cout << (k + x * a) << '\n';
  }
  solve();
}

signed main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif


  solve();
}
