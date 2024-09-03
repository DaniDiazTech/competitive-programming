// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  int j = 0;
  while ((1 << j) <= k){
    j++;
  }
  j--;

  // jth power
  vector<int> a;
  a.push_back(k + 1);
  a.push_back(k + 1 + (1 << j));
  a.push_back(k - (1 << j));

  for (int i =0 ;i < j; i++) a.push_back(1 << i);
  for (int i =j + 1 ;i < 20; i++) a.push_back(1 << i);

  cout << a.size() << endl;
  for (auto x : a) cout << x << ' ';
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
