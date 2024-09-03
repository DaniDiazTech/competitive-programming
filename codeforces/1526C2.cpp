// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[n];
  for (int i =0 ;i < n ; i++) cin >> a[i];

  priority_queue<int> pq;
  ll cur = 0;
  int pos = 0;
  int ans = 0;
  for (int i = 0;i < n; i++){
    if (a[i] >= 0){
      cur += a[i];
      pos++;
    }
    else{
      if (cur + a[i] >= 0){
        pq.push(-a[i]);
        cur += a[i];
      }
      else{
        if (pq.size() && -a[i] < pq.top()){
          cur += pq.top();
          cur += a[i];
          pq.pop();
          pq.push(-a[i]);
        } 
      }
    }
    ans = max(ans, (int)pq.size() + pos);
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
