#include <bits/stdc++.h>
using namespace std;
vector<int> subset;
int n = 4;
// Recursive approach
// Define subset
void search(int k){
  if (k == n + 1){
    for (auto x: subset) cout << x << " ";
    cout << endl;
  }
  else{
    // include k in the subset
    subset.push_back(k);
    search(k + 1);
    subset.pop_back();
    // Don't include it
    search(k + 1);
  }
}
void print2d(vector<vector<int>> &v){
  for (auto s: v){
    for (auto x: s){
      cout << x << " ";
    }
    cout << endl;
  }
}
void iterative_approach(vector<vector<int>> &v, int n){
  // Generates all the subsets of an array from 1 to n
  v.push_back({});
  for (int i = 1; i <= n; i++){
    vector<int> s = {};
    int until = v.size();
    for (int j = 0; j < until; j++){
      s = v[j]; 
      s.push_back(i);
      v.push_back(s);
    }
  } 
}

int main(){
  // recursive
  search(1);
  cout << "\nITERATIVE APPROACH!!!!\n";
  vector<vector<int>> sb;
  iterative_approach(sb, 4);
  print2d(sb); 
}