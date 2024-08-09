// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 2e5 + 10;

ll f[N];

void solve(){
  int l,r; cin >> l >> r;
  ll ans = 0;
  int x = l;

  while (x){
    x/=3;
    ans += 2;    
  }

  l++;
  ans += f[r] - f[l - 1];

  cout << ans << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  for (int i = 1 ;i < N; i++){
    int x = i;
    while (x){
      x/=3;
      f[i]++;
    }
    f[i] += f[i - 1];
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
