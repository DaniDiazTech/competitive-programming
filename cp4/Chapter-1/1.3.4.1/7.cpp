#include<bits/stdc++.h>
using namespace std;
int main(){
  string s = "";
  int n = 10;
  for (int i = 0; i < n; i++){
    s.push_back('A' + i);
  }

  do{
    cout << s << '\n';
  }
  while (next_permutation(s.begin(), s.end()));
}