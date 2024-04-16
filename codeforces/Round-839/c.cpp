// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int k, n; cin >> k >> n;
  vector<int> a(k);
  a[0] = 1;
  for (int i =1 ;i < k; i++){
    if (a[i - 1] + k - 1 <= n){
      a[i] = a[i - 1] + i;
    }
    else{
      a[i] = a[i - 1] + 1;
    }
  }
  for (auto x: a) cout << x << " ";
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
