// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const string yes = "YES", no = "NO";

const int MAX = 4 * 1e5;
ll fact[MAX];

void solve(){
  string s; cin >>s;
  s.push_back('2');
  int n = s.size();
  char prev = '-';

  int cnt  = 0;
  int inv = 0; 
  ll ways = 1;
  
  for (int i = 0; i < n ; i++){
    if (s[i] == prev){
      cnt++;
    }
    else{
      if (cnt >0 ){
        inv += cnt;
        ways = (ways * (cnt  + 1)) % mod;
        cnt = 0;
      }
    }
    prev = s[i];
  }
  ways = (fact[inv] * ways) % mod;

  cout << inv << " " <<  ways << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  fact[0] = 1;
  for (ll i = 1; i < MAX; i++){
    fact[i] = (i * fact[i - 1]) % mod;
  }

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}

