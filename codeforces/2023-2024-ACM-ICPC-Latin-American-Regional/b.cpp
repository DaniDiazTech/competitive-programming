// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  int a[3 * n];
  for (int i =0 ;i < 3 * n; i++){
    cin >> a[i];
  }
  sort(a, a + (3 * n));

  bool ok = 0 ;
  int s1 = 0, s2 = 0;
  bool first = 1;
  for (int i =0 ;i < (3 * n); i++){
    if (first){
      s1 += a[i];
    }
    else{
      s2 += a[i];
      i++;
    }

    first = !first;
  }
  ok |= s1 != s2;
  s1 = s2 = 0;
  first = 1;

  for (int i = 3 * n- 1; i>=0; i--){
    if (first){
      s1 += a[i];
    }
    else{
      s2 += a[i];
      i--;
    }
    
    first = !first;
  }
  ok |= s1 != s2;

  cout << (ok ? "Y": "N") << '\n';
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
