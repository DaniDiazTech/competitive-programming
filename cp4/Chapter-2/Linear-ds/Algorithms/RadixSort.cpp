#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[], int n, int place, int base=10){
  int f[base] = {0}; 
  int b[n];

  for (int i =0; i < n; i++){
    f[(a[i] / place) % base]++;
  }

  for (int i = 1; i < base; i++) f[i] += f[i - 1];

  for (int i = n - 1; i>=0; i--){
    int d= (a[i] / place) % base;
    b[f[d] - 1] = a[i];
    f[d]--;
  }

  for (int i = 0; i < n; i++) a[i] = b[i];
}

void radix_sort(int a[], int n, int base = 10){
  int mx = a[max_element(a, a + n) - a];
  for (int place  = 1; mx / place > 0; place *= base){
    counting_sort(a, n, place, base);
  }
}