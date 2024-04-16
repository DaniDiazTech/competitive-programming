// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> d(2 * n);
  for (int i =0 ;i < 2 * n; i++) cin >> d[i];
  sort(d.rbegin(), d.rend());
  ll sum = 0;
  set<ll> s;
  for (int i =0;i < n; i++){
    ll num = d[2 * i]  - 2 * sum;
    ll div = 2 * (n - i);
    ll x = num / div;
    if (d[2 * i] == d[2 * i + 1] && (num % div == 0) && x > 0 && !(s.count(x))){
      sum += x;
      s.insert(x);
    }
    else{
      cout << no << '\n';
      return;
    }
  }
  cout << yes << '\n';
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
