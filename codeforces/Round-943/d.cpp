// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, k, b, s;
  cin >> n >> k >> b >> s;
  b--;
  s--;
  vector<ll> p(n), a(n), pb(n), ps(n);
  for (auto &x: p) cin >> x, x--;
  for (auto &x: a) cin >> x;

  vector<bool> viss(n), visb(n);

  // s
  ll maxs = 0, maxb = 0, acum = 0;
  for (int i = s, j = k; !viss[i] && j > 0; i = p[i], j--){
    viss[i] = 1;
    ps[i] += j * a[i];
    // ps[s] is not correct
    maxs = max(ps[i], maxs);
    acum += a[i];
    ps[p[i]] += acum;
  }

  acum = 0;
  
  for (int i = b, j = k; !visb[i] && j > 0; i = p[i], j--){
    visb[i] = 1;
    pb[i] += j * a[i];
    // ps[s] is not correct
    maxb = max(pb[i], maxb);
    acum += a[i];
    pb[p[i]] += acum;
  }
  
  // for (int i = 0;i < n; i++){
  //   cout << ps[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0;i < n; i++){
  //   cout << pb[i] << " ";
  // }

  if (maxb > maxs){
    cout << "Bodya";
  }
  else if (maxb < maxs){
    cout << "Sasha";
  }
  else{
    cout << "Draw";
  }
  cout << endl;
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
    solve();
  }
}
