#include <bits/stdc++.h>
using namespace std;

bool unique_elements(int arr[], int n){
  // First sort
  sort(arr, arr + n);
  // If there are repeated elements they must be
  // side by side (adjacent)
  for (int i = 0; i < n - 1; i++){
    if (arr[i] == arr[i + 1]) return false;
  }
  return true;
}

int main(){
  int a[] = {1, 2, 3, 1, 21, 2, 7};
  int b[] = {1, 8, 3, 2, 21, 6, 9};
  int n = sizeof(a) / sizeof(a[0]);
  // Do they have repeated elements?
  cout << "A: " << ((unique_elements(a, n)) ? "NO": "YES") << endl;
  cout << "B: " << ((unique_elements(b, n))  ? "NO":"YES") << endl;
}