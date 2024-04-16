// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m), p(m), s(m);
  for (auto &x: a)cin >> x;
  for (auto &x: b)cin >> x;

  sort(b.begin(), b.end());
  sort(a.begin(), a.end());
  ll ans = 0;

  // suffix

  for (int i = 0;i < n; i++){
    // first ai with last bi
    s[m - i - 1] = abs(b[m - i - 1] - a[i]);
    if (i > 0) s[m - i - 1] += s[m - i];
  }

  // prefix
  for (int i = 0;i < n; i++){
    p[i] = abs(b[i] - a[n - i - 1]);
    if (i > 0) p[i] += p[i - 1];
  }

  ans = max(s[m - n], p[n - 1]);

  for (int i = 0; i < n - 1; i++){
    ans = max(ans, p[i] + s[m - n + i + 1]);
  }
  cout << ans << '\n';
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