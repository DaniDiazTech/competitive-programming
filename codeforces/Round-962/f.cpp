// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, k ; cin >> n >> k;

  vector<ll> a(n), b(n);
  for (auto &x: a) cin >> x;
  for (auto &x: b) cin >> x;

  // let r be the smallest value for which we can set all
  // the elements in A to, using at most k operations

  ll l = -1, r = 1e9 + 20;
  vector<ll> modified(n);
  ll contrib = 0, fx = 0, f_x = 0;

  while (l + 1 < r){
    ll m = (l + r) / 2;
    fx = 0;
    for (int i =0 ;i < n; i++){
      // set 
      ll x = max(0ll, (a[i] - m + (b[i])) / b[i] );

      fx += x;
    }

    if (fx <= k){
      r = m;
      contrib = 0;
      f_x = fx;
      for (int i =0 ;i < n; i++){
        // set 
        ll x = max(0ll, (a[i] - m + (b[i])) / b[i] );
        contrib += a[i] * x - b[i] * (x * (x - 1)) / 2;

        modified[i] = max(a[i] - x * b[i], 0ll);
      }
    }
    else l = m;
  }

  ll ans = contrib;
  priority_queue<pair<int,int>> pq;
  for (int i = 0;i < n; i++){
    pq.push({modified[i], b[i]});
  }

  k -= f_x;

  while (k && pq.size()){
    ll el = pq.top().first, bi = pq.top().second;
    pq.pop();
    ans += el;
    ll now = max(0ll, el - bi);
    if (now > 0)
      pq.push({now, bi});
    k--;
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
