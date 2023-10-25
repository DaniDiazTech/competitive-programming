// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> odd, even;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    if (x & 1){
      odd.push_back(x);
    }
    else even.push_back(x);
  }
  if (odd.size() == n || even.size() == n){
    cout << yes << '\n';
    return;
  }
  bool f= 0 ;
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  f |= (even[0] > odd[0]);

  cout << (f ? yes: no)<< '\n';
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
