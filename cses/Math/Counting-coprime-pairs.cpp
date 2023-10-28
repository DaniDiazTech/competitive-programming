// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e3;

int sieve[N];
vector<int> primes;

void solve(){
  int n;
  cin >> n;
  vector< pair <int, vector<int> > > v;

  int ones = 0;
  int mx = 1;
  for (int i =0 ;i  < n; i++){
    int x;
    cin >> x;
    if (x == 1){
      ones++;
      continue;
    }
    int prod = 1;
    vector<int> mn;
    for ( auto p: primes ){
      if (p * p > x){
        break;
      }
      bool ok = 0;
      while ( x % p == 0  ){
        ok = 1;
        x/=p;
      }
      if (ok)
        mn.push_back(p);
    }

    if (x > 1){
      prod *= x;
      mn.push_back(x);
    }

    mx = max(prod, mx);
    v.push_back( {prod, mn} );
  } 
  int ans = (ones * (ones - 1) / 2) + ones * (v.size())  ;

  sort(v.begin(), v.end());

  vector<int> dp(mx + 1);

  for (int i = 0; i < v.size(); i++){

    auto p = v[i];
    
    ans += i - ( dp[p.first] );

    // populate
    for (auto x: p.second ){
      
      

    }
  }

  cout << ans << '\n';

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  for (int i =2;i < N; i++){
    if (sieve[i]) continue;
    primes.push_back(i);
    for (int j = i;j < N; j+=i){
      sieve[j] = 1;
    }
  }

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
