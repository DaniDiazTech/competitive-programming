// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int n = s.size();
  int a[n], b[n], ans[n];

  for (int i = 0;i < n ; i++){
    a[i] = pow(10, (int)(s[i] - 'A'));
    ans[i] = 0;
  }

  int mx = -1;
  ll sum = 0;

  for (int i = n-1; i>=0; i--){
    b[i] = mx;
    mx = max(mx, a[i]);
  }

  for (int i = 0; i < n; i++){
    if (b[i] > a[i]){
      ans[i] -= a[i];
    }
    else{
      ans[i] += a[i];
    }
    if (i > 0) ans[i] += ans[i - 1];
  }
  
  ll mxsum = ans[n - 1];
  int re = 1;
  for (int j = 0; j < 5; j++){
    ll sm = 0, ssm = 0;
    for (int i =0 ;i < n; i++){

      ll x=  ans[n - 1] - ans[i] + ssm - sm + re;
      cout << "CUR: " << a[i] << " " << re << ' ' << i << " ANS: " << x << " RIGHT: " << ans[n - 1] - ans[i] << endl;

      mxsum = max(mxsum, x);
      if (a[i] >= re (b[i] <= a[i]) ){
        ssm += a[i];
      }
      else sm +=  a[i];
    }
    re *= 10;
  }


  cout << mxsum << endl;
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
