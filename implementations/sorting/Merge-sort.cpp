#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int  n){
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
// Merge two subarrays
// Create two sorted subarrays and merge them
// p -> start
// q -> middle of the array
// r -> end
// Merge two subarrays L and M into arr
void mymerge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int a, int b){
  // Recursive
  if (b > a){
    int k = (a + b) >> 1;
    merge_sort(arr, a, k);
    merge_sort(arr, k + 1, b);
    mymerge(arr, a, k, b);
  }

}

int main(){
  int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  merge_sort(arr, 0, n - 1);
  print(arr, n);
}