// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6;

 
void solve(){
  ll n;
  cin >> n;
  set<ll> ans;

  ll l = 1, r  = 1e6;
  while (l + 1 < r){
    ll m = (l + r) / 2;
    if ( m * m <= n){
      l = m;
    }
    else r = m;
  }

  // get all divisors of n


  ll nn = n;
  vector<int> div;

  for (int i = 1; i <= l; i++){
    if (n % i == 0){
      div.push_back(i);
      div.push_back(n / i);
    }
  }

  for (int i = 2; i <= l; i++){
    vector<int> pal;
    ll k = n;
    while (k){
      pal.push_back(k % i);
      k/=i;
    }
    bool ok = 1;
    for (int j = 0;j < pal.size() / 2;j++){
      if (pal[j] != pal[pal.size() - j - 1] ){
        ok = 0;
      }
    }
    if ( ok ){
      ans.insert(i);
    }

  }

  for (auto d: div){
    ll b = (n / d) - 1;
    if ( b >= 2){
      vector<int> pal;
      ll k = n;
      while (k){
        pal.push_back(k % b);
        k/=b;
      }
      bool ok = 1;
      for (int j = 0;j < pal.size() / 2;j++){
        if (pal[j] != pal[pal.size() - j - 1] ){
          ok = 0;
        }
      }
      if ( ok ){
        ans.insert(b);
      }

    }
  }

  if (ans.size()){
    for (auto x: ans) cout << x << " ";
  }
  else{
    cout << "*";
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