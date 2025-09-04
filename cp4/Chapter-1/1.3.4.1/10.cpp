#include<bits/stdc++.h>
using namespace std;
signed main(){
  string ans, s;
  while (cin >> s){
    if (s.size() == 3){
      if (islower(s[0]) && isdigit(s[1]) && isdigit(s[2])) ans += "***";
      else ans += s;
    }
    else ans += s;

    ans += " ";
  }
  cout << ans << endl;
}