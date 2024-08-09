// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, f, k;
  cin >> n >> f >> k;
  int val;
  vector<pair<int,int>> v;
  for (int i =0;i < n; i++){
    int x; cin >> x;
    v.push_back({x, i});
    if (i + 1 == f){
      val = x;
    }
  }
  sort(v.rbegin(), v.rend());
  int s = 0;
  int i;
  for (i = 0;i < n; i++){
    if (i + 1 > k) break;
    if (v[i].first == val){
      s = 1;
    }  
    
    if (s == 1 && v[i].first != val){
      s = 2;
    }
  }
  if (i + 1 < n && v[i + 1].first != val)
  if (s == 0)
    cout << no;
  else if (s == 1)
    cout << "MAYBE";
  else
    cout << yes;

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
