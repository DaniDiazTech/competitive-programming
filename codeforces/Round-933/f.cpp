// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
const ll INF = 1e10;
void solve(){
  int n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n), B, C;
  set<ll> b, c;
  ll  mx = 0;
  
  for (int i = 0;i < n; i++){
      cin >> a[i];
      if (i > 0 ){
        mx = max(a[i] - a[i - 1], mx);    
      }
  }
  
  for (int i = 0;i < m; i++){
      int x; cin >> x;
      b.insert(x);
  }
  
  for (int i = 0;i < k; i++){
      int x; cin >> x;
      c.insert(x);
  }
  
  for (auto x:b) B.push_back(x);
  for (auto x:c) C.push_back(x);
  
  ll l = 0, r = 0;
  int count = 0;
  for (int i =1 ; i < n; i++){
      if (a[i] - a[i - 1] == mx){
        count++;
        l = a[i - 1], r = a[i];
      }
  }
  
  if (count > 1){
      cout << mx << endl;
      return;
  }
  
  m = B.size(), k = C.size();

  ll avg = (l + r) / 2;
  ll in, best;
  in = best = INF;
  
  int jump = 2;

  for (int i =0 ;i < m; i++){
      // search for
      ll search = avg - B[i];
      int ind = lower_bound(C.begin(), C.end(), search) - C.begin();
      
      for (int j = ind - jump; j <= ind + jump && j < k; j++){
          if (j < 0) continue;
          
          ll y = B[i] + C[j];

          ll pay = max(y - l, r - y);
          
          if (l < y && y < r && pay < best){
              in = y;
              best = pay;
          }
      }
  }

  
  if (in != INF) a.push_back(in);
  
  sort(a.begin(), a.end());
  ll final = 0;
  for (int i =1; i <  (int) a.size(); i++){
    final = max(final, a[i] - a[i - 1]);
  }
  
  cout << final << endl;
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