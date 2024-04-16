// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

vector<pair<int,int>> v;
void range(int l , int r){
  if (l == r){
    return;
  }
  else{
    range(l, r - 1); 
    v.push_back({l, r});
    for (int j = l; j < r; j++){
      v.push_back({j , j});
    }
    range(l, r - 1);
  }
}

void solve(){
  int n;
  cin >> n;
  vector<int> a(n + 1), dp(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i =1 ; i <= n; i++){
    dp[i] = max(dp[i], dp[i - 1] + a[i]);
    for (int j = i; j <= n; j++){
      dp[j] = max(dp[j], (j - i + 1) * (j - i + 1) + dp[i - 1]);
    }
  }
  
  int i = n;
  while (i >= 1){
    if (dp[i] == dp[i - 1] + a[i]){
      i--;
    } 
    else{
      int r = i;      
      int l = 1;
      for (; l < i; l++){
        if (dp[l - 1] + (r - l + 1) * (r - l + 1) == dp[r]){
          break;
        }
      }
      i = l - 1;
      for (int j = l; j <= r; j++){
        if (a[j] > 0)
          v.push_back({j, j});
      }
      range(l, r);
      v.push_back({l, r});
    }
  }

  cout << dp[n] << ' ' << v.size() << '\n';
  for (auto x: v){
    cout << x.first << " " << x.second << '\n';
  }
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
