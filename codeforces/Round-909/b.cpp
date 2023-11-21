// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  ll a[n], p[n + 1];
  p[0] = 0;
  for (int i = 0;i < n; i++){
    cin >> a[i];
    p[i+ 1] = a[i];
    p[i + 1] += p[i];
  }

  vector<int> div;
  // get divisors of d
  for (int i = 1; i * i <= n; i++){
    if ( n % i == 0 ){
      div.push_back(i);
      div.push_back(n / i);
    }
  }
  
  ll mx = 0;
  for (auto d: div){

    ll curmn = 1e15, curmx = 0; 

    for (int i = d; i <= n; i+=d){
      curmn = min(curmn, p[i] - p[i - d]);
      curmx = max(curmx, p[i] - p[i - d]);
    }
    // cout << "d: " << d << " " <<  curmx << " " << curmn << endl;
    mx = max(mx, curmx - curmn);
  }
  cout << mx << endl;
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
