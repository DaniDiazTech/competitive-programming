// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n,q;
  cin >> n >> q;
  string a, b;
  cin >> a >> b;
  vector<vector<int>> A(n, vector<int>(26)), B;
  B= A;

  for (int i = 0;i < n; i++){
    A[i][a[i] - 'a']++;
    B[i][b[i] - 'a']++;
    if (i > 0){
      for (int j =0;j < 26; j++){
        A[i][j] += A[i - 1][j];
        B[i][j] += B[i - 1][j];
      }
    }
  }

  while (q--){
    int l, r; cin >> l >> r;
    l--;r--;

    int count = 0;
    for (int i = 0;i < 26; i++){
      int ina = (A[r][i] - (l > 0 ? A[l - 1][i]: 0));
      int inb = (B[r][i] - (l > 0 ? B[l - 1][i]: 0));

      count += abs(ina - inb);
    }

    cout << count / 2 << endl;
  }
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
