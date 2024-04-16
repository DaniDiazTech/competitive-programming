// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int n;
string p, s;
vector<bool> b(10);
set<string> ans;

void perm(int i){
  if (i == n){
    ans.insert(p);
    return;
  }

  for (int j = 0; j < n ; j++){
    if (!b[j]){
      b[j] = 1;
      p.push_back(s[j]);
      perm(i + 1);
      p.pop_back();
      b[j] = 0;
    }
  }

}


void solve(){
  cin >> s;
  n = s.size();
  perm(0);
  cout << ans.size() << endl;
  for (auto x: ans) cout << x << endl;
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
