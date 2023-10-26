// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n;
  cin >> n;
  vector<int> ans;
  for (int i= 2; i < n; i++){
    vector<int> v;
    int l = n;

    while (l){
      v.push_back( l % i );
      l/=i;
    }
    bool ok = 1;
    for (int i =0 ;i < v.size() / 2; i++){
      if (v[i] != v[v.size() - 1 - i]) {
        ok = 0;
        break;
      }
    }
    if ( ok ) ans.push_back(i);
  }

  if ( ans.size() ){
    for (auto x : ans) cout << x << " ";
    cout << '\n';
  }
  else{
    cout << "*" << '\n';
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
