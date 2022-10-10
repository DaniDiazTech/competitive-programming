#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    if (s == "4" || s == "1" || s == "78") cout << "+";
    else {
      if (s.size() >= 3) {
        if (s.substr(s.size() - 2, 2) == "35") {
          cout << "-";
        }
        else if (s.substr(0, 3) == "190" && s.size() > 3) {
          cout << "?";
        }
        else cout << "*";
      }
      else{
        cout << "+";
      }
    }

    cout << endl;
  }
}