// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> v;
  bool f = 1;
  for (int i =0 ; i <n ;i++){
    ll x; cin >> x;
    if (v.empty()){
      cout << 1;
      v.push_back(x);
      continue;
    }
    bool l = 0;

    if (f){
      if (x >= v.back()){
        v.push_back(x);
        l = 1;
      }
      else if (x <= v.front()){
        v.push_back(x);
        l = 1;
        f = 0;
      }
    }
    else{
      if (x <= v.front() && x >= v.back()){
        v.push_back(x);
        l = 1;
      }
    }
    cout << l;
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
