// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int prev = -1;
  set<char> v, c;
  v.insert('a');
  v.insert('e');
  c.insert('b');
  c.insert('c');
  c.insert('d');
  vector<string> ans;
  string cur = "";

  for (int i = 0;i < n - 1; i++){
    if (c.count(s[i])){
      if (c.count(s[i + 1])){
        cur += s[i];
        ans.push_back(cur);
        cur = "";
      }
      else{
        if (cur.size()){
          ans.push_back(cur);
        }
        cur = "";
        cur += s[i];
      }
    }
    else{
      cur += s[i];
    }
  }
  if (cur.size()){
    cur += s[n - 1];
    ans.push_back(cur);
  }


  for (int i =0 ;i < ans.size(); i++){
    if (i> 0) cout << ".";
    cout << ans[i];
  }
  cout << '\n';
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
