// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define int long long

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


void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  int x, y, g;
  bool f = find_any_solution(a, b, -c, x, y, g);
  if (f){
    cout << x << " " << y << '\n';
  }
  else{
    cout << -1 << '\n';
  }
}

int32_t main() {
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
