// Look if an array of numbers is ordered
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  bool sorted = true;


  // k starting as the first element, then being replaced by the current number
  k = arr[0];
  for (int element : arr) {
    if (element < k) {
      sorted = false;
      break;
    }
    k = element;
  }

  // if else one liner
  string r = (sorted == true) ? "Ordenado" : "Desordenado";
  cout << r;
}