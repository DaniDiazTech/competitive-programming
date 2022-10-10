#include <bits/stdc++.h>
using namespace std;
int main(){
  map<string, string> mp = {
   {"HELLO", "ENGLISH"},
   {"HOLA", "SPANISH"},
   {"HALLO", "GERMAN"},
   {"BONJOUR", "FRENCH"},
   {"CIAO", "ITALIAN"},
   {"ZDRAVSTVUJTE", "RUSSIAN"},
  };
  string s;
  int i = 1;
  while (cin >> s){
    if (s == "#") break;
    cout << "Case " << i << ": ";
    if (mp[s] == ""){
      cout << "UNKNOWN";
    }
    else cout << mp[s];
    cout << endl;
    i++;
  }
}