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
  set<char> st;
  for (int i = 0;i < n; i++){
    st.insert(s[i]);
  }
  vector<char> a;
  for (auto x: st){
    a.push_back(x);
  }
  map<char, char> mp;
  for (int i = 0;i < (int)a.size() ; i++){
    mp[a[i]] = a[a.size() - i - 1];
  }


  for (int i =0 ; i < n; i++){
    cout << mp[s[i]];
  }
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