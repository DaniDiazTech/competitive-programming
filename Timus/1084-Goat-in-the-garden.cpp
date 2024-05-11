// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const double PI  = 3.141592653589793; 

double area(double r, double x){
  double w  = sqrt(r * r - x * x);
  return 0.5 * (x * x -  (x * w) - ( r * r * asin(x / r) ) );
}

double calc(double r, double start, double end){
  if (start >= end){
    return 0;
  }
  return area(r, end) - area(r, start);
}

void solve(){
  double l, r;
  cin >> l >> r;  
  double ans = 0;
  if (2 * r <= l){
    ans =  PI  * r * r;
  }
  else{
    ans = l * l - 8 * calc(r, sqrt(2) * 0.5 * r, l / 2);
  }
  cout << ans << '\n';
  
}

void solve2(){
  double l, r; cin >> l >> r;
  if (2 * r <= l){
    cout << PI * r * r << '\n';
    return;
  }
  double ans;
  if (r >= sqrt(2) * 0.5 * l){
    ans = l * l;
  }
  else{
    double x = l / 2.0;
    double h = sqrt(r * r - x * x);
    double angle = acos(x / r);
    ans = PI * r * r - 4 * ( (angle * r * r) - (h * x) );
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  cout << setprecision(3) << fixed;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  // solve();
  solve2();
}
