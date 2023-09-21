// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int l, int m, int r){
  int cnt= 0;

  int leftsize = m - l + 1, rightsize = r - m;
  int left[leftsize], right[rightsize];


  for (int i = 0; i < leftsize; i++){
    left[i] = a[l + i];
  }
  for (int i = 0; i < rightsize; i++){
    right[i] = a[m + i + 1];
  }

  cout << "ORIGINAL: " << endl;
  for (int i =l; i <=r; i++) cout << a[i] << " ";
  cout << endl << "LEFT: " << endl;
  for (int i = 0; i < leftsize; i++) cout << left[i] << " ";
  cout << endl << "RIGHT: " << endl;
  for (int i = 0; i < leftsize; i++) cout << right[i] << " ";
  cout << endl;

  int i = 0, j = 0;

  while (i < leftsize && j < rightsize){
    if (right[j] < left[i]){
      cnt+= rightsize - i;
      a[l + i +  j] = right[j];
      j++;
    }
    else{
      a[l + i + j] = left[i];
      i++;
    }
  }
  while (i < leftsize){
    a[l + i + j] = left[i];
    i++;
  }
  while (j < rightsize){
    a[l + i + j] = right[j];
    j++;
  }
  cout << "CNT: " <<  cnt<< endl;
  return cnt; 
}
// Inclusive mergesort

int mergesort(int a[], int l, int r){
  if (l >= r) return 0 ;
  int cnt =0;
  int m = l + (r - l) / 2;  
  cnt += mergesort(a, l, m);
  cnt += mergesort(a, m + 1, r);
  cnt += merge(a, l, m, r);
  return cnt;
}
int main(){
  int n = 8;
  int a[n];
  srand(time(NULL));
  cout << "Original: " << endl;
  for (int i =0 ; i < n; i++){
    a[i] = rand() % 32;
    cout << a[i] << " "; 
  }
  cout << endl;

  cout << mergesort(a, 0 , n - 1) << endl;

  cout << "Sorted: " << endl;
  for (int i =0 ; i < n; i++){
    cout << a[i] << " "; 
  }
  cout << endl;


  int b[] = {3, 2, 1, 4};
  cout << mergesort(b, 0 , 3) << endl;
  for (int i =0; i < 4; i++) cout << b[i] << " ";
}