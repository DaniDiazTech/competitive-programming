// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  map<pair<int,int>,int> mp;
  int  d= 0, k = 0;
  for (int i = 1;i <= n; i++){
    char ch; cin >> ch;
    d += ch == 'D';
    k += ch == 'K';
    int g = gcd(d, k);
    cout << ++mp[{d / g, k / g}] << ' ';
  }
  cout << '\n';

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
