// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  ll a[n];
  for (int i =0;i < n; i++){
    cin >> a[i];
  }
  set<ll> s;
  s.insert(0);
  ll o = 0, e = 0;
  for (int i =0 ;i < n; i++){
    if (i & 1) o += a[i];
    else e += a[i];
    if (s.count(o - e)){
      cout << yes << '\n';
      return;
    }
    s.insert(o - e);
  }
  cout << no << '\n';
  
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
