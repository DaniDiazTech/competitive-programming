#include <bits/stdc++.h>
using namespace std;

int grid_paths(int n, int  m){
  // Simplest input
  if (n == 1 || m == 1){
    return 1;
  }
  return grid_paths(n - 1, m) + grid_paths(n, m - 1); 
}

int main(){
  int n = 4;
  int m = 4;
  cout << grid_paths(n, m) << endl;
}