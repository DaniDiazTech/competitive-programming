// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string s; cin >> s;
  s.push_back('$');
  vector<pair<char,int>> v;
  char cur = s[0];
  int cnt = 1;
  for (int i = 1;i <= n; i++){
    if (s[i] == cur){
      cnt++;
    }
    else{
      v.push_back({cur, cnt});
      cur= s[i];
      cnt = 1;
    }
  }
  auto v2 = v;
  int ans = n, ans2= n;

  for (int i = 1;i < v.size(); i++){
    if (v[i -1].second == 0){
      continue;
    }
    else{
      int x = min(v[i].second, v[i - 1].second);
      v[i - 1].second -= x;
      v[i].second -= x;
      if (v[i].second == 0) swap(v[i], v[i - 1]);
      ans -= 2 * x;
    }
  }

  for (int i = v2.size() - 2; i >= 0; i--){
    if (v2[i + 1].second == 0){
      continue;
    }
    else{
      int x = min(v2[i].second, v2[i + 1].second);
      v2[i + 1].second -= x;
      v2[i].second -= x;
      if (v2[i].second == 0) swap(v2[i], v2[i+ 1]);
      ans2 -= 2 * x;
    }

  }

  cout <<min(ans, ans2)  << endl;

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
