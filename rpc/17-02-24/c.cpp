// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  // Ace (A), 2, 3, 4, 5, 6, 7, 8, 9, 10 (T), Jack (J),
  // Queen (Q), King (K).
  ll val[n], rank[n];
  //map rank to freq
  map<ll,ll> mp;
  for (int i = 0;i < n; i++){
    char ch; cin >> ch;
    if (ch == 'A'){
      val[i] = rank[i] = 1;
    }
    else if (ch == 'T'){
      rank[i] = val[i] = 10;
    }
    else if(ch == 'J'){
      rank[i] = 11;
      val[i] = 10;
    }
    else if(ch == 'Q'){
      rank[i] = 12;
      val[i] = 10;
    }
    else if (ch == 'K'){
      rank[i] = 13;
      val[i] = 10;
    }
    else{
      rank[i] = val[i] = (int)(ch - '0');
    }

    // freq
    mp[rank[i]]++;
  }


  // First condition
  ll dp[n][16];
  for (int i =0 ;i < n; i++){ for (int j = 0;j < 16; j++) dp[i][j] = 0;}
  dp[0][val[0]] = 1;

  for (int i = 1;i < n; i++){
    dp[i][val[i]] += 1;
    for (int j = 1; j <= 15; j++){
      dp[i][j] += dp[i - 1][j];

      if (j + val[i] <= 15){
        // val = 4
        // j = 1
        //j + val = 5 -> 1
        dp[i][j + val[i]] += dp[i - 1][j]; 
      }
    }
  }
  ll ans = dp[n - 1][15] * 2;
  // cout << ans << endl;
  // 2.
  ll c = 0;
  for (auto x: mp){
    c += (x.second * (x.second - 1)) / 2;
  }

  ans += c * 2;

  // cout << ans << endl;

  // 3.
  sort(rank, rank + n);
  vector<pair<int,int>> v;
  int cnt = 0, prev = -1;

  for (int i = 0 ;i < n; i++){
    if (prev == rank[i]){
      cnt++;
    }
    else{
      if (prev != -1)
        v.push_back({prev, cnt});
      
      prev = rank[i];
      cnt = 1;
    }
  }

  v.push_back({rank[n - 1], cnt});

  // for (auto x: v){
  //   cout << x.first << " " << x.second << endl;
  // }

  int m = v.size();
  ll l = 0;

  for (int i = 1 ;i < m; i++){
    if (v[i - 1].first != v[i].first - 1){
      if (i - l >= 3){
        ll cnt = 1;
        for (int j = l; j<= i - 1; j++){
          cnt *= v[j].second ;
        }
        ans += cnt * (i - l);
      }

      l = i; 
    }
  }

  if (m - l >= 3){
    ll cnt = 1;
    for (int j = l; j<= m - 1; j++){
      cnt *= v[j].second;
    }
    ans += cnt * (m - l);
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
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
