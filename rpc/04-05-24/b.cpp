// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

/*
Extended euclidean algorithm:
Calculates gcd of two positive numbers, a and b,
and coefficients of Bezut identity:
ax + by = gcd(a, b)

O(log min(a, b))
*/
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

/*
Finds a solution to the linear diophantine equation:
ax + by = c, using extended euclidean algorithm.

Manages a, b < 0. If the gcd of a and b doesn't divide c
there aren't integer solutions. Scales x, and y after running extended gcd.
O(log min(a, b))
*/
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
/*
Counts all solutions of the ax + by = c equation
with constraints for x and y.

Uses the fact that we can modify the linear diophantine values for x and y,
and still get a valid equation.

x = x0 + k(b / g)
y = y0 - k(a / g)

O(log min(a, b))
*/
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
  int x, y, g;
  if (!find_any_solution(a, b, c, x, y, g))
    return 0;
  a /= g;
  b /= g;

  int sign_a = a > 0 ? +1 : -1;
  int sign_b = b > 0 ? +1 : -1;

  shift_solution(x, y, a, b, (minx - x) / b);
  if (x < minx)
    shift_solution(x, y, a, b, sign_b);
  if (x > maxx)
    return 0;
  int lx1 = x;

  shift_solution(x, y, a, b, (maxx - x) / b);
  if (x > maxx)
    shift_solution(x, y, a, b, -sign_b);
  int rx1 = x;

  shift_solution(x, y, a, b, -(miny - y) / a);
  if (y < miny)
    shift_solution(x, y, a, b, -sign_a);
  if (y > maxy)
    return 0;
  int lx2 = x;

  shift_solution(x, y, a, b, -(maxy - y) / a);
  if (y > maxy)
    shift_solution(x, y, a, b, sign_a);
  int rx2 = x;

  if (lx2 > rx2)
    swap(lx2, rx2);
  int lx = max(lx1, lx2);
  int rx = min(rx1, rx2);

  if (lx > rx)
    return 0;
  return (rx - lx) / abs(b) + 1;
}

/*
Upper bounds:
Because x = x0 + k(b / g) and y = y0 - k(a / g),
if (x > (c / a)) -> ax + by = c, y = (c - ax) / b
then y < 0, thus we can set:
Maxx: (c / a) + 1, as a valid upper bound
Similarly,
Maxy: (c / b) + 1
*/
int find_non_negative(int a, int b, int c){
  return find_all_solutions(a, b, c, 1, (c / a) + 1, 1, (c / b) + 1);
}


void solve(){
  int a, k, d;
  cin >> d >> a >> k;
  cout << (find_non_negative(a, k, d) > 0 ? 1 : 0) << '\n';
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
