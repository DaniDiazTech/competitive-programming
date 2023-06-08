#include <bits/stdc++.h>
using namespace std;

int main(){
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  string s;
  int k; cin >>s >> k;
  set<char> st;
  map<char, int> mp;
  int ans = -1;
  for (int l = 0, r =0; r < (int)s.size(); r++){
    mp[s[r]]++;
    st.insert(s[r]);
    if (st.size() > k){
      while (1){
        mp[s[l]]--;
        if (mp[s[l]] == 0){
          // Removed a character
          st.erase(s[l]);
          l++;
          break;
        }
        l++;
      }
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
}