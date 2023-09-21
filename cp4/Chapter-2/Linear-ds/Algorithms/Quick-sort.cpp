#include <iostream>
#include <time.h>
using namespace std;

// return index of the pivot
int partition(int a[], int start, int end){
  // Randomized pivot
  int random_index = start + (rand() % (end - start));

  // Gets random pivot to the end
  swap(a[random_index], a[end]);
  int pivot = a[end];

  // Partition the array

  // First index in which the elements are greater than pivot
  int index = start;
  // excluding end which is the pivot
  for (int i = start ; i < end; i++){
    if (a[i] <= pivot){
      swap(a[i], a[index]);
      index++;
    } 
  }
  swap(a[index], a[end]);
  return index;
}


void quicksort(int a[], int start, int end){
  // Invalid segment or only one element
  if (start >= end) return;
  // There'll be a pivot such that all elements to the left are 
  // less or equal and to the right all greater
  int pivot = partition(a, start, end);
  quicksort(a, start, pivot - 1);
  quicksort(a, pivot + 1, end);
}


int main(){
  int n = 40;
  int a[n];
  srand(time(NULL));
  for (int i =0 ;i < n; i++){
    a[i] = rand() % 233;
    cout << a[i] << " ";
  }
  cout << endl;
  quicksort(a, 0, n - 1);
  for (int i =0 ;i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}