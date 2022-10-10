#include <bits/stdc++.h>
using namespace std;
// Print all possible subsets
void print(vector<int> &v, int size){
  for (int i = 0; i < size; i++){
    cout << v[i] << " ";
  }
  cout << "\n";
}
void printPowerSet(vector<int> &s, vector<int> &out, int i){
  if (i < 0){
    print(out, out.size());
    return;
  }

  // Include current element
  out.push_back(s[i]);
  printPowerSet(s,  out, i - 1);
  // backtrack
  out.pop_back();
  // Remove duplicate elements
  while (s[i] == s[i - 1]){
    i--;
  }

  printPowerSet(s, out, i - 1);
}

int main(){
  vector<int> v;
  // 20 elements? This is gonna take a while :)
  // O(n * 2^n) -> 20 * 2^20 :0
  for (int i =1; i<=20;i++) v.push_back(i);
  vector<int> out;
  printPowerSet(v, out, v.size()  - 1);
}