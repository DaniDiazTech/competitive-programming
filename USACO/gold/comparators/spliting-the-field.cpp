// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const ll inf = 1e18;
void solve(){
  int n;
  cin >> n;
  vector<pair<ll,ll>> c(n);
  ll mnx = inf, mny = inf, mxx  = 0, mxy = 0;
  for (auto &u: c){
    cin >> u.first >> u.second;
    mnx = min(mnx, u.first);
    mxx = max(mxx, u.first);

    mny = min(mny, u.second);
    mxy = max(mxy, u.second);
  }

  ll a = (mxx - mnx) * (mxy - mny);
  vector<ll> mxr(n, - 1), mxl(n, - 1), mnr(n, inf), mnl(n, inf);
  // Y boundary
  sort(c.begin(), c.end(), [&](pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second < b.second;
  });

  // x maximum and minima
  for (int i = 0;i < n - 1; i++){
    mxl[i] = max(c[i].first, (i > 0 ? mxl[i - 1] : -1ll)); 
    mnl[i] = min(c[i].first, (i > 0 ? mnl[i - 1] : inf));
  }

  for (int i = n - 1;i >= 0; --i){
    mxr[i] = max(c[i].first, (i < n - 1 ? mxr[i + 1] : -1ll)); 
    mnr[i] = min(c[i].first, (i < n - 1 ? mnr[i + 1] : inf));
  }
  ll ans = 0;

  for (int i = 0;i < n - 1; i++){
    ll a1 = (mxl[i] - mnl[i]) * (c[i].second - c[0].second);
    ll a2 = (mxr[i + 1] - mnr[i + 1]) * (c[n - 1].second - c[i + 1].second);
    ans = max(ans, a - a1 - a2);
  }

  sort(c.begin(), c.end());

  // y maximum and minima
  for (int i = 0;i < n - 1; i++){
    mxl[i] = max(c[i].second, (i > 0 ? mxl[i - 1] : -1ll)); 
    mnl[i] = min(c[i].second, (i > 0 ? mnl[i - 1] : inf));
  }
  for (int i = n - 1;i >= 0; --i){
    mxr[i] = max(c[i].second, (i < n - 1 ? mxr[i + 1] : -1ll)); 
    mnr[i] = min(c[i].second, (i < n - 1 ? mnr[i + 1] : inf));
  }

  for (int i = 0;i < n - 1; i++){
    ll a1 = (mxl[i] - mnl[i]) * (c[i].first - c[0].first);
    ll a2 = (mxr[i + 1] - mnr[i + 1]) * (c[n - 1].first - c[i + 1].first);
    ans = max(ans, a - a1 - a2);
  }

  cout << ans << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #else
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
