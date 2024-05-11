// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ld long double


const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ld binpow(ld a, int m){
  ld ans = 1;
  while (m){
    if (m & 1) ans *= a;
    a *= a;
    m /= 2;
  }
  return ans;
}

void solve(){
  ull N, R, P;
  cin >> N >> R >> P;

  ld n = N;
  ld r = R;
  ld p = P;

  int l = -1, h = 5000;
  ld x = 1.0 + ((r * 1.0) / 100.0);
  ld d = p / n;
  while (l + 1 < h){
    int m = (l + h) / 2;
    ld y = binpow(x,m);
    if (y < d) l = m;
    else h = m; 
  }
  cout << h << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    cout << "Case " << t << ": ";
    solve();
  }
}
