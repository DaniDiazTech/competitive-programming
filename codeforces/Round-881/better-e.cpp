// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> v;
  for (int i = 0;i < m; i++){
    int l, r; cin >> l >> r;
    v.push_back({l, r});
  }

  int q;
  cin >> q;
  vector<int> Q(q);
  for (int i = 1; i<= q; i++){
    cin >> Q[i - 1];
  }

  int l = -1, r = q;

  while (l + 1 < r){
    int m = (l + r) / 2;
    // build vector
    vector<int> pref(n + 1);
    for (int i = 0;  i <= m; i++){
      pref[Q[i]] = 1;
    }
    for (int i = 1 ; i <= n; i++){
      pref[i] += pref[i - 1];
    }

    // process queries
    bool f = 0;
    for (auto range: v){
      int x = pref[range.second] - pref[range.first - 1];
      if (x >= ((range.second - range.first + 1) / 2) + 1){
         f = 1;
         break;
      }
    }

    if (f){
      r = m;
    }
    else l = m;

  }

  cout << (r==q? -1 : r + 1) << endl;

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
