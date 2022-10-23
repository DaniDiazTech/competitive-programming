#include <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  string s;
  cin >> s;

  bool ok = true;
  if (s.size() <= 2){
    set<int> st(s.begin(), s.end());
    if (st.size() != 1){
      ok = false;
    }
  }

  map<char, int> mp;
  for (auto x: s){
    mp[x]++;
  }

  string f = "";
  string middle = "";
  string l = "";
  for (auto x: mp){
    if (!ok) break;
    if (x.second & 1){
      if (middle.size()){
        ok = false;
        break;
      }
      else{
        middle = string(x.second, x.first);
        continue;
      }
    }
    else{
      f+= string(x.second / 2, x.first);
      l+= string(x.second / 2, x.first);
    }
  }
  reverse(l.begin(), l.end());
  cout << ((ok) ? (f + middle + l): "NO SOLUTION") << endl;
}