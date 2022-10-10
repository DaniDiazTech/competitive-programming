#include <bits/stdc++.h>
using namespace std;

// Recursive
int factorial(int n){
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
// Iterative
int i_factorial(int n){
  if (n == 0) return 1;
  int f = 1;
  for (int i = 1; i <= n; i++){
    f *= i;
  }
  return f;
}
int main(){
  int n = 7;
  cout << factorial(n) << endl;
  cout << i_factorial(n) << endl;
}