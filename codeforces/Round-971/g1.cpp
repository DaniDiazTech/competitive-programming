// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> a(n), b(n), ans(n);
  for (auto &x: a) cin  >> x;

  for (int i = 0;i < n; i++){
    b[i] = a[i] - i;
  }

  int l = 0, r= 0;
  map<int,int> mp;
  priority_queue<pair<int,int>> pq;

  while (r - l + 1 <= k){
    mp[b[r]]++;
    pq.push({mp[b[r]], b[r]});
    r++;
  }

  while (r <= n){

    while (mp[pq.top().second] != pq.top().first){
      pq.pop();
    }
    ans[l] = pq.top().first;

    if (r == n) break;
    // update
    mp[b[r]]++;
    mp[b[l]]--;
    pq.push({mp[b[r]], b[r]});
    pq.push({mp[b[l]], b[l]});

    r++;
    l++;
  } 

  for (int i = 0;i <= n - k; i++){
    ans[i] = k - ans[i];
  }

  while (q--){
    int l, r; cin >> l >> r;
    l--;
    cout << ans[l] << endl;
  }

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
