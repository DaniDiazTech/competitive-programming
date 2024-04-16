// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, k; cin >> n >> k;
  vector<ll> v(n + 2), p(n + 2), s(n + 2);
  v[n + 1] = v[0] = p[0] = p[n + 1] = s[0] = s[n + 1] = 0;
  for (int i = 1; i <= n; i++) cin >> v[i]; 
  for (int i = 1; i <= n; i++){
    p[i] = p[i - 1] + v[i];
    s[n - i + 1] = s[n - i + 2] + v[n - i + 1];
  }

  ll left = ( k / 2) + (k & 1), right = (k / 2);
  // left
  ll l = 1, r = n;
  ll lover = 0, rover = 0;
  for (; l <= n; l++){
    if (p[l] > left){
      lover = left - p[l - 1];
      break;
    }
  }
  for (; r >= 1; r--){
    if (s[r] > right){
      rover = right - s[r + 1];
      break;
    }
  }

  if (r < l){
    cout << n;
  }
  else if (r == l){
    if (v[r] <= rover + lover){
      cout << n;
    }
    else{
      cout << n - (r - l + 1);
    }
  }
  else{
    cout << n - (r - l + 1);
  }

  cout << endl;

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
