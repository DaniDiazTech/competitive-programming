#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n = 20;
  int a[n];
  for (int i = 0;i < n; i++) a[i] = i + 1;
  for (int mask = 0; mask < (1 << n); mask++){
    for (int j = 0; j < n; j++){
      if (j & mask){
          // printf("%d ", a[j]);
          cout << a[j] << " ";
      }
    }
    // printf("\n");
    cout << endl;
  }
}