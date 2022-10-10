#include <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  string x;
  int f  = 0;
  while (getline(cin, x)){
    string out ="";
    for (int i = 0; i < (int)x.size(); i++){
      if (x[i] == '"'){
        if (f % 2){
          cout << "\'\'";
        }
        else{
          cout << "``";
        }
        f++;
        continue;
      }
      cout << x[i];
    }
    cout << endl;
  }
}