// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  multiset<int> s, t;

  vector<int> v;
  for (int i=0 ;i < n; i++){
    int x; cin >> x;
    x %= m;
    v.push_back(x);
    s.insert(x);
  }
  for (int i=0 ;i < n; i++){
    int x; cin >> x;
    x %= m;
    t.insert(x);
  }

  for (auto x: v){
    auto it = t.find(x);
    if (it != t.end()){
      t.erase(it);
      auto itt  = s.find(x);
      s.erase(itt);
    }
  }

  // all the rest
  v.clear();
  for (auto x: s){
    v.push_back(m - x);
  }


  for (auto x : v){
    auto it = t.find(x);
    if (it != t.end()){
      t.erase(it);
    }
  }

  cout << (t.size() ? "NO" : "YES") << endl;
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
