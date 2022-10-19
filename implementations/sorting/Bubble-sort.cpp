#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int  n){
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void bubble_sort(int arr[], int n){
  for (int i = 0; i < n; i++){
    // Moves the biggest element found to the last position
    // print(arr, n);
    for (int j = 0; j < n - 1; j++){
      if (arr[j] > arr[j + 1]){
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}


int main(){
  int arr[8] = {1, 3, 5, 6, 7, 4, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubble_sort(arr, n);
  print(arr, n);
}