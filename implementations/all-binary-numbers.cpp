#include <bits/stdc++.h>
using namespace std;

void search(int k, int n, string s){
  if (k == n + 1){
    cout << s << endl;
  }
  else{
    // include 1
    s.push_back('1');
    search(k + 1, n, s);
    // not include 1
    s.pop_back();
    s.push_back('0');
    search(k + 1, n, s);
  }
}
