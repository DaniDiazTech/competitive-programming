// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll dp[n];
  ll mn = 1e12;
  for (int i = 0;i < n; i++){
    cin >> a[i];
    b[i] =  a[i];
    mn = min(a[i], mn);
  }
  sort(a.begin(), a.end());
  ll ans = 0 ;
  bool f = 1;
  for (int i =0 ;i <n ; i++){
    if (b[i] == mn){
      // check if sorted 
      for (int j = i; j < n - 1; j++){
        if (b[j] > b[j + 1]){
          f = 0;
          break;
        }
      }
      break;
    }
    // int l = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    // ans += n - l;
    ans++;
  }

  cout << (f ? ans : -1) << endl;

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
