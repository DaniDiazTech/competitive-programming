#include <bits/stdc++.h>

using namespace std;

// In place prefix sum
void calc_prefix_sum(int arr[], int size, int res[]){
  res[0] = arr[0];

  for (int i = 1; i < size; i++){
    res[i] = res[i - 1] + arr[i];
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  int n = sizeof(arr) / sizeof(arr[0]);

  int prefix_sum_arr[n];

  calc_prefix_sum(arr, n, prefix_sum_arr);

  for (auto i: prefix_sum_arr) cout << i << " ";
}