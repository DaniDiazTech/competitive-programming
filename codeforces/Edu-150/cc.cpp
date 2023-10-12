// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s;
  cin >> s;
  int n = s.size();

  int ten[5];
  int l = 1;
  for (int i = 0 ; i < 5; i++){
    ten[i] = l;
    l *= 10;
  }

  int a[n], b[n]; 
  for (int i =0 ;i < n; i++){
    a[i] = s[i] - 'A';
  } 

  // Compute E
  int E[n][5];
  ll ans[n];
  vector<pair<int,int>> v(n);
  for (int i =0 ;i < n ; i++){
    b[i] = 0;
    ans[i] = 0;
    v[i]= {0,0};
    for (int j = 0; j < 5; j++) E[i][j] = 0;
  }
  // freq map {freq, pos}
  map<int, pair<int,int>> mp;
  // store {freq, pos}
  for (int j = 0;j < 5; j++){
    mp[j] = {0, 0};
  }
  l = 0;
  for (int i = n - 1; i>= 0; i--){
    for (int k = a[i] + 1; k < 5; k++){
      if (mp[k].first){
        v[i].first += mp[k].first;
        v[i].second = mp[k].second;
      }
    }
    if (v[i].first == 0){
      ans[i] += ten[a[i]];
    }
    else{
      ans[i] -= ten[a[i]];
    }

    // process
    if (v[i].first == 1){
      E[v[i].second][a[i]]++;
      // cout << v[i].second << " E "  << E[v[i].second][a[i]] << endl;;
    }
    // store for next push
    mp[a[i]].first++;
    mp[a[i]].second = i;
    b[i] = l;
    l = max(l, a[i]);
  }
  for (int i =1 ;i < n ; i++){
    ans[i] += ans[i - 1];
  }
  
  ll mx = ans[n - 1];
  // cout << "INIT: " << mx << endl;
  for (int j = 0; j < 5; j++){
    // replace by k
    int neg = 0, hold = 0;
    vector<int> cur(5);
    // cout << "---------------\n";
    for (int i = 0; i < n; i++){
      ll sum = 0;
      for (int k = 0; k < j; k++){
        sum -= cur[k] * ten[k];
      }
      for (int k = j; k < 5; k++){
        sum += 2 * E[i][k] * ten[k];
        sum += cur[k] * ten[k];
      }
      ll x = ans[n - 1] - ans[i] - neg - hold + sum + ten[j] * (b[i] > j ? -1 : 1);
      // cout << i << " " << j << " X: " << x << " CUR: " << char( a[i] + 'A') << " " << ten[j] <<  endl;
      // cout << "SUM: " << sum << endl;
      // cout << "NEG: " << neg <<  " HOLD: " << hold << " SUFF: " << ans[n - 1] - ans[i] << endl;
      // cout << v[i].first << " " << v[i].second << endl;
      // cout << b[i] << " " << j << endl;
      mx = max(mx, x);

      if (v[i].first > 1){
        neg += ten[a[i]];
      }
      else if (v[i].first == 0){
        // pos += ten[a[i]];
        cur[a[i]]++;        
      }
      else hold += ten[a[i]];
    }
  }
  cout << mx  << endl;
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
