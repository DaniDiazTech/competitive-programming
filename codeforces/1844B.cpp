// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int k = n / 2;
  if (n >= 3) cout << 3 << " ";
  int j = 4;
  for (int i = 1; i < k; i++){
    cout << j << ' '; 
    j++;
  }
  cout << 1 << " ";
  for (int i = k + 1; i < n - 1; i++){
    cout << j << ' ';
    j++;
  }
  if (n >= 2) cout << 2 << " ";
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
