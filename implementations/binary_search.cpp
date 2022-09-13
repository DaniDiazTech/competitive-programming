#include <bits/stdc++.h>

using namespace std;

// The element could not be in the array
int binary_search(int arr[], int size, int search){
  int l = 0, r = size - 1; 
  int mid;

  while (r >= l){
    mid = (l + r) >> 1; // Bitwise division 

    if (arr[mid] < search){
      l = mid + 1;
    } 
    else if (arr[mid] > search){
      r = mid - 1;
    }
    else return mid;
  }

  return -1;
}

// The element is not in the array, but it is in a pile
// Prefix sum
// lower_bound()
int binary_search_prefix(int arr[], int size, int search){
  int l = 0, r = size - 1; 
  int mid;

  while (r > l){
    mid = (l + r) >> 1; // Bitwise division 

    if (arr[mid] < search){
      l = mid + 1;
    } 
    else if (arr[mid]){
      r = mid;
    }
    else return mid;
  }

  return l;
}
