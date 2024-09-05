// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  priority_queue<int> pq;
  vector<int> a(n);
  for (auto &x: a) cin >> x;


  ll ans = 0;
  for (int i =0 ;i < n; i++){
    if (a[i] == 0){
      if (pq.size()){
        ans += pq.top();
        pq.pop();
      }
    }
    else{
      pq.push(a[i]);
    }
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