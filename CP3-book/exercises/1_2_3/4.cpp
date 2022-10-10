#include <bits/stdc++.h>
using namespace std;
// Given n random integers, print the distinct (unique) integers in sorted order.
int main(){
  set<int> s;
  int x;
  while (cin >> x) s.insert(x);
  for (auto it = s.begin(); it != s.end(); it++) cout << *it << " ";
}