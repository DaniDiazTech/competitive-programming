#include <bits/stdc++.h>
using namespace std;
int main(){
  // Special word
  // One letter, two digits.
  string s = "line: a70 and z72 will be replaced, aa24 and a872 will not";
  cout << s << endl;
  string out;
  // With for
  char prev = s[0];
  out += prev;
  for (int i = 1; i < (int)s.size();){
    if (isalpha(s[i])){
      if(!isalpha(prev)){
        if (i +2 < (int)s.size()){
          if (isdigit(s[i + 1]) && isdigit(s[i + 2])){
            if (i +3 < (int)s.size()){
              if (!isdigit(i + 3)){
                out += "***";
                i += 3;
                continue;
              }
            }
            else{
              out += "***";
              i += 3;
              continue;
            }
          }
        }
      } 
    }
    prev = s[i];
    out += prev;
    i++;
  }
  cout << out << endl;

  // With Regex
  regex pattern("\\s[a-z][0-9]{2}\\s");
  string out2 = regex_replace(s, pattern, " *** ");
  cout << out2 << "\n";
}