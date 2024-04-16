// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  map<int,int> mpb, mpa;
  for (auto &x: a) cin >> x;
  for (auto &x: b){
    cin >> x;
    mpb[x]++;
  }
  int ans = 0, common = 0;
  for (int i = 0; i < m; i++){
    if (mpb[a[i]] != 0){
      mpa[a[i]]++;
      if (mpb[a[i]] >= mpa[a[i]]){
        common++;
      }
    }
  }
  if (common >= k) ans++;

  for (int i = m; i < n; i++){
    // exit i - m, enter i
    if (mpb[a[i - m]] != 0){
      if (mpb[a[i - m]] >= mpa[a[i - m]]){
        common--;
      }
    }
    mpa[a[i - m]]--;

    // enter i
    mpa[a[i]]++;
    if (mpb[a[i]] != 0){
      if (mpb[a[i]] >= mpa[a[i]]){
        common++;
      }
    }
    if (common >= k) ans++;
  }
  
  cout << ans << endl;
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
