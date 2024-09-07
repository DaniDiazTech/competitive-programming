// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b = "What are you doing while sending ";
string c = "? Are you busy? Will you send ";

vector<ll> dp; // size of f(i)
int m;

char f(ll n, ll k){
  if (n < m && dp[n] < k){
    return '.';
  }

  if (n > 0 && k >= 1){
    // cur = b"f(i-1)"c"f(i-1)"?
    // in b?

    if (k <= (int)b.size()){
      return b[k - 1];  
    } 
    if (k == (int)b.size() + 1){
      return '"';
    }
    k -= (int)b.size() + 1;
    // not in b
    if (n >= m){
      // Must be in f(n - 1, k)
      return f(n - 1, k);
    }
    else{
      // Could be in f(n -1)"
      if (dp[n - 1] >= k){
        return f(n - 1, k);
      }
      if (k == dp[n - 1] + 1){
        return '"';
      }

      k -= dp[n - 1] + 1;

      // in c" ?
      if ((int)c.size() >= k){
        return c[k - 1];
      }
      if (k == (int)c.size() + 1){
        return '"';
      }
      k -= (int)c.size() + 1;
      
      // Could be in f(n -1)"
      if (dp[n - 1] >= k){
        return f(n - 1, k);
      }
      if (k == dp[n - 1] + 1){
        return '"';
      }
      if (k == dp[n - 1] + 2){
        return '?';
      }

      // Must be out
      return '.';

    }
  }

  if (k > (int)a.size()){
    return '.';
  }
  else{
    return a[k - 1];
  }
}


void solve(){
  
  ll n, k; cin >> n >> k;
  cout << f(n, k);
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  ll l = 1e18;
  ll cur = a.size();


  while (cur <= l){
    dp.push_back(cur);
    cur = b.size() + 1 + cur + 1 + c.size() + 1 + cur + 2;
  }
  dp.push_back(cur);
  m = dp.size();

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
