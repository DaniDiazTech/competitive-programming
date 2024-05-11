// // Made by Daniel Diaz (@Danidiaztech)
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// const int mod = 1e9 + 7;
// const string yes = "YES", no = "NO";

// ll n;
// double p;
// double binpow(double a, ll n){
//   if (n == 0) return 1;
//   if (n == 1) return a;
//   double x = binpow(a, n / 2);
//   double xx = 2 * x * (1 - x);
//   if (n & 1){
//     return xx * (1 - p) + (1 - xx) * p;
//   }
//   return xx;
// }

// void solve(){
//   cin >> n >> p;
//   cout << setprecision(20);
//   cout << (1 - binpow(p, n)) << '\n';
// }

// int main() {
//   cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

//   #if LOCAL
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//   #endif

//   int tc = 1;
//   // cin >> tc;

//   for (int t = 1; t <= tc; t++){
//     solve();
//   }
// }
