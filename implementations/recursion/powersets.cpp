#include <bits/stdc++.h>
using namespace std;
void powerset_r(int k,  int n, vector<int> &v, vector<int> sol){
  if (k == n){
    // Base case
    for (auto x: sol) cout << x << ' ';
    if (!sol.size()) cout << "{}";
    cout << endl;
  }
  else{
    sol.push_back(v[k]);
    powerset_r(k + 1, n, v, sol);
    sol.pop_back();
    powerset_r(k + 1, n, v, sol);
  }
}

void powerset_i(vector<int> v){
  for (int mask = 0; mask < (1 << v.size()); mask++){
    // sizeof -> size of the element in bits
    // bitset -> sequence of n bits
    // cout << bitset<sizeof(v.size())>(mask) << endl;
    if (mask == 0){
      cout << "{}" << endl;
      continue;
    }
    for (int i= 0; i < (int)v.size(); i++){
      // include it 
      if (mask & (1 << i)){
        cout << v[i] << " ";
      }
      // Don't
    }
    cout << endl;
  }
}


int main(){
  // 1 2 3 4
  int n = 4;
  vector<int> v(n);
  vector<int> solution;
  for (int i = 1; i <= n; i++) v[i - 1] = i;
  v.push_back(76);
  n++;
  cout << "RECURSIVE" << endl;
  powerset_r(0, n, v, solution);
  cout << "ITERATIVE" << endl;
  powerset_i(v);
}