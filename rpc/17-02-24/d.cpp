// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  string s; cin >> s;
  int n = s.size();


  map<char, int> mp;
  // ATGC
  mp['A'] = 0;
  mp['T'] = 1;
  mp['G'] = 2;
  mp['C'] = 3;

  int a[4][n + 1];

  for (int i = 0;i < 4; i++){
    for (int j = 0;j <= n; j++) a[i][j] = 0;
  }

  for (int i = 1; i <= n; i++){
    a[mp[s[i - 1]]][i]++;
  }

  for (int i = 0; i < 4; i++){
    for (int j = 1; j <= n; j++){
      a[i][j] += a[i][j - 1];
    }
  }

  int m; cin >> m;
  while (m--){
    int l, r; cin >> l >> r;
    vector<pair<int, int>> v;
    for (int i = 0; i < 4; i++){
      v.push_back({a[i][r] - a[i][l - 1], i});
    }

    sort(v.rbegin(), v.rend(), [](const pair<int,int> &a, pair<int,int> &b){
      return (a.first == b.first ? a.second > b.second : a.first < b.first);
    });
    for (auto x: v){
      // cout << x.first << " " << x.second << endl;
      if (x.second == 0) cout <<'A';
      else if (x.second == 1) cout << 'T';
      else if (x.second == 2) cout << 'G';
      else cout << 'C';
      // cout << endl;
    }
    cout << '\n';
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
