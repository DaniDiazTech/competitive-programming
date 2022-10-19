#include <bits/stdc++.h>
using namespace std;
int partitions(int n, int m){
  // Base cases
  if (m  == 0 || n < 0){
    return 0;
  }
  else if (n == 0){
    return 1;
  }
  return partitions(n - m, m) + partitions(n, m - 1);
}
int main(){
  int n = 6, m = 4;
  cout << partitions(n, m) << endl;
}